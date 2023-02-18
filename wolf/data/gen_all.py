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
    suits = cmdlinearg('suits')
    print(len(suits) * 13)
    for s in suits:
        for i in range(1, 14):
            print(i, s)

if __name__ == "__main__":
    main()
