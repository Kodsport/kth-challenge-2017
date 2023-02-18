#!/usr/bin/env python3

MOD = 1000000007
DP = {}

def F(X):
    if X <= 1: return 0
    if X in DP: return DP[X]
    odd = (X + 1) // 2
    even = X // 2
    ans = (even + 2 * (odd - 1) + F(odd) + F(even)) % MOD
    DP[X] = ans
    return ans

L, R = map(int, input().split())

print((F(R) - F(L - 1) + MOD) % MOD)
