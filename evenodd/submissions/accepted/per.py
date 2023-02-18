#!/usr/bin/env python3
def F(n):
    tot = tail = part = 0
    m = 1
    while 2*m <= n:
        tail = 2*tail + 3*m//2
        tot += tail
        part += 2 * (n % m)
        if n % (2*m) >= m:
            part += 2*m - (n % m) + tail
        m = 2*m
    return tot+part

L, H = map(int, input().split())
print((F(H)-F(L-1)) % (10**9+7))
