#!/usr/bin/python3

import sys
import random
import math

def main():
    random.seed(int(sys.argv[-1]))
    print(random.randint(1, 10**4))

if __name__ == "__main__":
    main()
