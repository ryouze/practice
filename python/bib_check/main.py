"""
Download a list of predatory publishers to a TXT file.

pip3 install -r requirements.txt
python3 main.py
"""
import logging

from bs4 import BeautifulSoup
from bs4.element import ResultSet
from requests import HTTPError, Session

# output txt file containg predatory publishers
FILEPATH: str = r"./publishers.txt"


class Web:
    def __init__(
        self,
        url: str = "https://beallslist.net/",
        timeout: int = 16,
        sort_alphabetically: bool = True,
    ) -> None:
        self.url: str = url
        self.timeout: int = timeout
        self.sort_alphabetically: bool = sort_alphabetically
        # cached variables
        self._webpage = None
        self._publishers: list = list()
        return None

    def _download_webpage(self) -> BeautifulSoup:
        """
        Download webpage containing a list of predatory publishers and convert it to BeautifulSoup object.

        If failed, raise.

        Returns:
            BeautifulSoup: Downloaded webpage, to be used for scraping.
        """
        try:
            logging.debug(f"trying to download webpage '{self.url}'")
            with Session() as s:
                # download list of predatory publishers
                r = s.get(self.url, timeout=self.timeout)
                # if not OK response, raise
                r.raise_for_status()
                # if OK, set utf-8 encoding
                r.encoding = "utf-8"
        except HTTPError as e:
            logging.error(f"failed to download webpage due to a network issue ({e})")
            raise
        except Exception as e:
            logging.error(f"failed to download webpage ({e})")
            raise
        else:
            try:
                self._webpage: BeautifulSoup = BeautifulSoup(
                    r.content, features="html.parser"
                )
            except Exception as e:
                logging.error(f"failed to convert webpage to soup ({e})")
                raise
            else:
                logging.debug(f"ok: downloaded webpage ({self.url})")
                return self._webpage

    def _get_publishers(self) -> list:
        """
        Download and extract a list of predatory publishers.

        If failed, raise.

        Returns:
            list: Predatory publishers.
        """
        if not self._webpage:
            logging.debug("webpage not cached, downloading now")
            self._webpage = self._download_webpage()
        to_replace: dict = {
            "\xa0": " ",  # hard space or a no-break space
            "\u200b": " ",  #  zero-width space
            "’": "'",
            "“": '"',
            "”": '"',
            "–": "-",
            " .": ".",
            " ,": ",",
            " :": ":",
            " ;": ";",
            "( ": "(",
            "( ": "(",
            " )": ")",
            ".)": ")",
        }
        try:
            # select container
            containers: ResultSet = self._webpage.find_all(
                "div",
                attrs={
                    "class": "wp-block-column",
                    "style": "flex-basis: 75%;",
                },
            )
            # get unordered lists
            for cont in containers:
                for li in cont.find_all("li"):
                    # recursively combine all tags
                    li: str = li.get_text(" ", strip=True)
                    # replace garbage like "&nbsp;"
                    for k, v in to_replace.items():
                        li = li.replace(k, v)
                        continue
                    li = li.strip()
                    self._publishers.append(li)
                    continue
                continue
            # sort alphabetically
            if self.sort_alphabetically:
                self._publishers.sort()
        except Exception as e:
            logging.error(f"failed to extract list of publishers from soup ({e})")
            raise
        else:
            logging.debug("ok: processed a list of predatory publishers")
            return self._publishers

    @property
    def publishers(self) -> list:
        """
        Get a list of predatory publishers from the internet.

        If cache unavailable, process now.
        If failed, raise.

        Returns:
            list: Predatory publishers.
        """
        # if not cached, get now
        if not self._publishers:
            self._publishers = self._get_publishers()
        return self._publishers


def main() -> None:
    # setup logger
    logging.basicConfig(
        datefmt="%G-%m-%d %T",
        format="%(asctime)s [%(levelname)s] %(filename)s : %(funcName)s() (%(lineno)d) - %(message)s",
        level=logging.DEBUG,
    )
    logging.info("downloading a list of predatory publishers")
    publishers: list = Web().publishers  # get predatory publishers from the web
    logging.info(f"ok: downloaded a list of '{len(publishers)}' predatory publishers")
    with open(file=FILEPATH, mode="w", encoding="utf-8") as f:
        f.write(
            "# A list of predatory publishers downloaded from https://beallslist.net/\n"
        )
        for p in publishers:
            f.write(p + "\n")
            continue
    logging.info(f"ok: saved list to '{FILEPATH}'")
    return None


if __name__ == "__main__":
    main()
