#!/usr/bin/env python3

from sys import stdin

n = int(stdin.readline())
days=0
printers=1
while(printers<n):
    days+=1
    printers*=2
print(days+1)
