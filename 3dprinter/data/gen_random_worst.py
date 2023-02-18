#!/usr/bin/python3

import sys
import random
import math

def main():
    random.seed(int(sys.argv[-1]))
    print(2**random.randint(1,13) + random.randint(-1,1))

if __name__ == "__main__":
    main()
