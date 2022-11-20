"""
Calculate grades in my University.

It's broken and I cba to fix it.

Steps:
1. Log into USOS.
2. Go to student's section -> final grades.
3. Hit CTRL + S, and save the entire webpage as HTML file called `my_grades.html`.
4. pip3 install -r requirements.txt
5. python3 main.py
6. View the results in `output.txt`.
"""

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
