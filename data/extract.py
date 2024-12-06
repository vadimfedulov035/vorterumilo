#!/usr/bin/env python

import os
import shutil
import re
import requests
import zipfile

from bs4 import BeautifulSoup



def clean(text):
    print("Starting cleaning...")

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

    print("Cleaned successfully...")

    return text


def download_file(url, zip_path):
    response = requests.get(url)
    if response.status_code == 200:
        with open(zip_path, 'wb') as f:
            f.write(response.content)
        print(f"Downloaded: {zip_path}")
    else:
        print(f"Failed to download file: {response.status_code}")


def unzip(zip_path, extract_path):
    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
        zip_ref.extractall(extract_path)
        print(f"Extracted: {extract_path}")


def check_existence(dataset):
    if os.path.exists(dataset):
        print(f"{dataset} found.")
        exit(0)
    else:
        print(f"No {dataset}. Downloading archive...")


def get_data(dataset):
    tekstaro_name = 'tekstaro_de_esperanto_html_sen_streketoj'
    tekstaro_website = 'https://tekstaro.com/elshutebla'
    tekstaro_zip = f'{tekstaro_name}.zip'

    tekstaro_url = f'{tekstaro_website}/{tekstaro_zip}'
    download_file(tekstaro_url, tekstaro_zip)

    unzip(tekstaro_zip, './')
    os.remove(tekstaro_zip)

    shutil.move(os.path.join(tekstaro_name, 'tekstoj'), 'tekstoj')
    shutil.rmtree(tekstaro_name)

    shutil.rmtree(os.path.join('tekstoj', 'bildoj'))


def write_data(dataset):
    tekstaro = ""

    files = [file for file in os.listdir('tekstoj')]
    for file in files:
        with open(os.path.join('tekstoj', file)) as f:
            data = f.read()
            gfg = BeautifulSoup(data, "lxml")
            tekstaro += gfg.get_text()
    shutil.rmtree('tekstoj')

    tekstaro = clean(tekstaro)

    with open(dataset, 'w') as f:
        f.write(tekstaro)


if __name__ == "__main__":

    dataset = os.path.join('data', 'tekstaro.txt')
    check_existence(dataset)

    get_data(dataset)
    write_data(dataset)
