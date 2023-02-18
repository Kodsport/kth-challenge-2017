#!/usr/bin/python3

import sys
import random
import math

def rnd(): return 2**random.choice(range(1, 60))
def main():
    random.seed(int(sys.argv[-1]))
    L, R = rnd(), rnd()
    if L > R: L, R = R, L
    print(L, R)

if __name__ == "__main__":
    main()
