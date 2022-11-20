"""
Compare survey results from Google Forms in two languages.

This barely works, I only used it to extract survey data for my BA.

It probably contains some awful pandas code as well.

Features:
* translates column names and answers into english
* removes participants who click the same answer more than X times (default: 80%)
* removes participants based on conditions, e.g., english not L2
* calculates when began to learn L2, age, gender, city size, uni year
* calculates mean values for each condition and language
* outputs: two cleaned up csv files (en & pl), participants' statistics, mean values condition
* output can be manually edited and used as input again (e.g., when removing based on z-score)

Steps:
1. Save results of two google forms as csv (e.g., `Survey research EN.csv`, `Survey research PL.csv`)
2. Place them into `./input` directory
3. Edit `./input/lang_db.json` so your column names and answers match (columns are queried by name instead of index)
4. Edit `./input/column_names.txt` so your custom column names match the condition (e.g., `congruent`)
5. Edit `comp.py` -> `remove_participants` to remove participants based on your conditions (e.g., if L2 not English)
6. Edit `main.py` to enable/disable features you want (e.g., removing participants)
7. Run `main.py`
8. See results in `./output`: processed csvs (based on your conditions), participant's statistics, means per each condition


**tip:** if you want to remove participants later (manually), edit the processed `res_*.csv` in `./output` and set `main.py` -> `enabled` -> `use_csv_from_input` to False; all the statistics will be re-done automatically.


example output:


| Participant | Language | Congruent | Incongruent |
| :---------: | :------: | :-------: | :---------: |
|      1      | English  |   6.70    |    6.17     |
|      2      | English  |   6.03    |    6.01     |
|      3      |  Polish  |   6.13    |    5.84     |


"""
from time import perf_counter
import comp
import fm
import logging
import sys
import target


def main():
    """
    main function
    """
    # start counting time
    start_time = perf_counter()
    # purge log file
    open("./log.log", "w").close()
    # setup logger
    logging.basicConfig(
        datefmt="%G-%m-%d %T",
        format="%(asctime)s [%(levelname)s] %(module)s.py : %(funcName)s() - %(message)s",
        encoding="utf-8",
        handlers=[logging.FileHandler("./log.log"), logging.StreamHandler(sys.stdout)],
        level=logging.INFO,
    )
    # (0) user toggles
    enabled = {
        "use_csv_from_input": True,  # if false then csv from "./output" will be loaded
        # useful if you want to edit them manually and then pass them to get_participants_statistics()
        "display_dataframes": True,  # if false then dataframes won't be printed out
        "get_participant_size": True,
        "get_began_english": True,
        "get_age": True,
        "get_gender": True,
        "get_city": True,
        "get_uni_year": True,
    }
    # (1) load language database: english/polish language database of column names and answers
    lang_db = fm.load_json(fn="./input/lang_db.json")
    # (2) load custom column names for questions
    colls_db = fm.load_columns(fn="./input/column_names.txt")
    # (3) load csvs, save a copy to "./output"
    means_en, means_pl = comp.get_clean_dfs(
        lang_db=lang_db,
        enabled=enabled,
        colls_db=colls_db,
        fn_survey_input_en="./input/Survey research EN.csv",
        fn_survey_input_pl="./input/Survey research PL.csv",
        fn_survey_output_en="./output/processed_EN.csv",
        fn_survey_output_pl="./output/processed_PL.csv",
        max_clicker_ratio=80,
    )
    # (4) combine both dataframes into one
    means_both = comp.combine_dfs(means_en=means_en, means_pl=means_pl, enabled=enabled)
    means_both = target.rename_index_to_participant(
        means_both
    )  # start numbering from 1, rename index to "Participant"
    # (5) calculate statistics (e.g., age, gender, city size):
    stats = comp.get_participants_statistics(
        lang_db=lang_db, means_en=means_en, means_pl=means_pl, enabled=enabled
    )
    # (6) save all columns in combined means to csv
    fm.save_dataframe_as_csv(obj=means_both, fn="./output/combined_all_columns.csv")
    # (7) save only mean values + "Language" column to csv
    colls = list(set(colls_db))
    colls.insert(0, "Language")
    means_both = means_both.filter(colls)
    fm.save_dataframe_as_csv(obj=means_both, fn="./output/combined_means_only.csv")
    # (8) save participants statistics to a txt file
    fm.save_dictionary_as_txt(
        obj=stats,
        header="[all data below has been calculated after the participants were removed]",
        fn="./output/stats.txt",
    )
    logging.info(f"program ended, took {round(perf_counter() - start_time, 3)} seconds")
    return


if __name__ == "__main__":
    main()
