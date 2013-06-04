#!/usr/bin/env python3

from sys import argv
from random import randint

chars = ["a", "b", "c", "d", "\n"]

with open(argv[1], mode="w") as f:
    for i in range(10000*1000):
        print(chars[randint(0, 4)], end="", file=f)
