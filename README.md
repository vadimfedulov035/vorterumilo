# Vorterumilo
## Esperanto morphological analyzer

Vorterumilo project aims to achieve fast and precize Esperanto morphological analysis via machine learning.

![cover](https://github.com/vadimfedulov035/vorterumilo/blob/main/cover.png)

Raw text -> Vorterumilo -> Morphological data

Theory:
1. Esperanto as a highly regular language can be analyzed automatically.
2. But there are some collision cases when one word can be viewed as several coinciding word structures ([homonyms](https://en.wikipedia.org/wiki/Homonym)), in which case the right one is deduced from the context.
3. Therefore such analysis would demand creating collision-conscious algorithm delegating decision-making to a LLM trained to solve homonyms.

Implementation:
1. Program part performs greedy and ungreedy searches on the word to identify morphemes.
2. If search results are not the same the word is a homonym.
3. AI part is asked to select valid solution based on the context.

Current version implements only the program part utilizing ungreedy search. It can serve on its own but will always provide the most obvious solution. It is planned to pretrain model like [Phi-3.5-mini-instruct](https://huggingface.co/microsoft/Phi-3.5-mini-instruct) on [Tekstaro](https://huggingface.co/datasets/veotri/tekstaro) to make use of both algorithms.

Vocabulary can be found in `./vocab/` files in char arrays with modulo 3 (word, eng, def) in [gperf format](https://developer.ibm.com/tutorials/l-gperf).

Translation consists of:

Up to 3 words ordered based on use frequency and intelligibility considerations for human or AI English speaker.

Definition consists of:
1. Simplicity level. Metric is based on [BRO groups](https://www.akademio-de-esperanto.org/verkoj/baza_radikaro_oficiala.html), except for the table words, which all belong to the 1 group for their ease of deduction one from another.
    * 1 - core
    * 2 - beginner 
    * 3 - elementary
    * 4 - intermediate
    * 5 - advanced
    * 6 - profecient
    * 7 - expert
    * 8 - mastery
    * 9 - extra
2. [Class](https://en.wikipedia.org/wiki/Part_of_speech) of the word's [lemma](https://en.wikipedia.org/wiki/Lemma_(morphology)) giving origin to its [family](https://en.wikipedia.org/wiki/Word_family). Metric is based on [BRO categories](https://www.akademio-de-esperanto.org/verkoj/baza_radikaro_oficiala.html), except for the extra words (simplicity = 9), which all belong to the mixed group.
    * i - interjection
    * c - conjunction
    * p - preposition
    * d - adverb
    * n - noun
    * a - adjective
    * v - verb
    * x - mixed
3. Word function (optional)
    * _ - space
    * ' - motion
    * ? - manner
    * @ - time
    * ! - intencity
    * \* - special word with custom definition

The word list is heavily inspired by [dictionary by undeconstructed](https://github.com/undeconstructed/vortaro), but is being improved by creating translations series according to the project guidelines.

## Compilation

`sudo apt install gperf -y` to install [gperf](https://developer.ibm.com/tutorials/l-gperf) dependency

`make -j` to compile

`make clean` to remove executable

`make cleaner` to remove executable and pregenerated perfect hashmaps

## Usage

`./vorterumilo` to start analysis of `./data/input.txt` to `./data/output.txt`

- [x] List, translate and classify base morphemes from [BRO](https://www.akademio-de-esperanto.org/verkoj/baza_radikaro_oficiala.html).
- [x] Program greedy and ungreedy search algorithms.
- [x] Add perfect hashing via [gperf](https://developer.ibm.com/tutorials/l-gperf).
- [x] Write Makefile.
- [ ] Pretrain Phi-3.5 (or similar model) on Tekstaro.
- [ ] Integrate llama.cpp API support.
- [ ] Unite program and AI parts as one.
- [ ] Make port to Windows (possibly with GUI).
