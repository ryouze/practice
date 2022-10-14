import logging
from time import perf_counter

from proc import calculate_main


if __name__ == "__main__":
    # setup logger
    logging.basicConfig(
        datefmt="%G-%m-%d %T",
        format="%(asctime)s [%(levelname)s] %(filename)s : %(funcName)s() (%(lineno)d) - %(message)s",
        level=logging.DEBUG,
    )
    start_time = perf_counter()
    calculate_main(filepath_open="./my_grades.html", filepath_save="./output.txt")
    logging.info(f"program ended, took {round(perf_counter() - start_time, 3)} seconds")
