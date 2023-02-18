#!/usr/bin/env python3
def solve(n):
    if n != 26: return n > 26
    has = [[0] for _ in range(4)]
    for _ in range(n):
        (v, s) = input().split()
        has['CDHS'.find(s)].append(int(v))
    return next((True for i in range(4) if max(has[i]) > len(has[i])-1), False)

print(['impossible','possible'][solve(int(input()))])
