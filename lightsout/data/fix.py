#!/usr/bin/env python3

from sys import stdin

n,m,l = map(int,stdin.readline().split())
print(n,m,l)
for _ in range(m):
    a,b = map(int,stdin.readline().split())
    print(a,b)
for _ in range(l):
    ll = list(map(int,stdin.readline().split()))
    print(ll[0],ll[1]," ".join([str(x-1) for x in ll[2:]]))
