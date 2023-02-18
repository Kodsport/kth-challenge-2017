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
    which = cmdlinearg('which')
    delta = 1 if which == 'lower' else -1
    default = 1 if which == 'lower' else 13
    cur = {}
    for c in "CDHS": cur[c] = default
    cards = [s for c in range(1, 14) for s in "CDHS"]
    which = random.sample(cards, n)
    print(len(which))
    for c in which:
        s = cur[c]
        cur[c] = cur[c] + delta
        print(s, c)

if __name__ == "__main__":
    main()
