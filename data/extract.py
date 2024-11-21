#!/usr/bin/env python

from os import listdir
from os.path import join

import re

from bs4 import BeautifulSoup

path = "texts"
files = [join(path, file) for file in listdir(path)]


def clean(text):

    # quotation marks
    text = re.sub(r"[“”]", "\"", text)
    text = re.sub(r"[‘’]", "\'", text)

    # brace content
    text = re.sub(r"\[.*\]", "", text)
    text = re.sub(r"\(.*\)", "", text)
    text = re.sub(r"\{.*\}", "", text)

    # flexible abbreviations
    text = re.sub(r"\bs-ro",      "sinjoro",      text)
    text = re.sub(r"\bs-ino",     "sinjorino",    text)
    text = re.sub(r"\bd-ro",      "doktoro",      text)
    text = re.sub(r"\bn-ro",      "numbero",      text)

    # non-flexible abbreviations
    text = re.sub(r"\beld\b",     "eldono",       text)
    text = re.sub(r"\bvol\b",     "volumo",       text)
    text = re.sub(r"\bkmp\b",     "komparu",      text)
    text = re.sub(r"\bktp\b",     "kaj tiel plu", text)

    # measure units
    text = re.sub(r"\bp(\.)?\b",  "paĝoj",        text)
    text = re.sub(r"\bno(\.)?\b", "nombro",       text)
    text = re.sub(r"\bkm(\.)?\b", "kilometroj",   text)
    text = re.sub(r"\bcm(\.)?\b", "centimetroj",  text)

    # extra spaces
    text = re.sub(r"[ ]+", " ", text)
    text = re.sub(r"[ ]+(,|\.|!|\?)", r"\1", text)
    text = re.sub(r"^[ ]+(\S)", r"\1", text, flags=re.M)

    # extra new lines
    text = re.sub(r"\n+", "\n", text)

    # roman numbers
    rom_num = "X"
    text = re.sub(r"\b[IVXLCDM]+\b", rom_num, text)

    # links
    link = "[RETEJO]"
    text = re.sub(r"\b(http|www).*\\?\b", link, text)
    text = re.sub(r"\b.+(php|html).*\b", link, text)

    return text


if __name__ == "__main__":
    for file in files:
        with open(file) as f:
            data = f.read()
            gfg = BeautifulSoup(data, "lxml")
            text = gfg.get_text()
            text = clean(text)
            print(text)
