#!/usr/bin/env python3
(n, m, k) = map(int, input().split())
E = [list(map(int, input().split())) for _ in range(m)]

B = [0]*(n+1)
for _ in range(k):
    (i, a) = map(int, input().split())
    B[i] = a


D = [0]*(n+1)
for (a, b) in E:
    if B[b]:
        D[a] += 1
    if B[a]:
        D[b] += 1

I = [0]*(n+1)
for (a, b) in E:
    if B[a] and not B[b]:
        I[a] += 1.0/D[b]
    if B[b] and not B[a]:
        I[b] += 1.0/D[a]

gain = 0
for i in range(n+1):
    if B[i]:
        gain += max(100*r*I[i] - (r*B[i])**2 for r in range(0, 11))

print(gain)
