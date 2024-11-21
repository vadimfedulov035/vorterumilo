#!/usr/bin/env python

import re
import shutil
import json



def clean(text):
    # delete comments
    text = re.sub(r"\s*\(.*?\)\s*", "", text)
    # delete a/an and to
    text = re.sub(r"\s*\b(a|an|the|to)\b\s*", " ", text)
    text = re.sub(r"^\s*", "", text)
    # delete etc
    text = re.sub(r", etc.", "", text)
    # change separator
    text = re.sub(r", ", "/", text)
    text = re.sub(r"; ", "/", text)
    return text.rstrip("'")


def set_words(filepath, base_words):
    with open(f"{filepath}", "r") as f:
        for line in f.readlines():
            res = re.search(r"\"(.+?)\"", line)
            if res is not None:
                base_words.append(res.group(1))
    return base_words


def set_base_words():
    base_words = []
    base_words = set_words("base.gperf", base_words)
    base_words = set_words("../cores.gperf", base_words)
    base_words = set_words("../meta.gperf", base_words)
    base_words = set_words("../suffixes.gperf", base_words)
    return base_words


def add_extra_words(base_words):
    results = []
    with open("extra.json", "r") as f:
        json_data = f.read()
        words = json.loads(json_data)

        extra_words = [w
                     for w in words
                     if w["radiko"].rstrip("'") not in base_words]

        for word in extra_words:
            root = word["radiko"].rstrip("'")
            root_w = " " * (16 - len(root))

            eng = clean(word["tradukoj"]["en"])
            eng_w = " " * (69 - len(root) - len(root_w) - len(eng))

            result = f'"{root}", {root_w} "{eng}", {eng_w} "0x"'
            if word not in base_words: 
                results.append(result)
            else:
                print(word)

    shutil.copy("base.gperf", "roots.gperf")
    with open("roots.gperf", "a") as f:
        for result in results:
            print(result, file=f)


if __name__ == "__main__":
    base_words = set_base_words()
    add_extra_words(base_words)
