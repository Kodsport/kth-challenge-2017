#!/usr/bin/python3

import sys
import random
import math

def cmdlinearg(name):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert False

def main():
    random.seed(int(sys.argv[-1]))
    n = int(cmdlinearg('n'))
    cards = [(c, s) for c in range(1, 14) for s in "CDHS"]
    which = random.sample(cards, n)
    print(len(which))
    for c, s in which:
        print(c, s)

if __name__ == "__main__":
    main()
