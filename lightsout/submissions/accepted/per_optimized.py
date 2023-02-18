#!/usr/bin/env python3
(n, m, l) = map(int, input().split())

adj = [[] for _ in range(n)]
S = [[] for _ in range(n)]

for _ in range(m):
    (u, v) = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

for _ in range(l):
    s = list(map(int, input().split()))
    S[s[0]].append(sum(2**i for i in s[2:]))

def elim(V, pre):
    r = 0
    if pre == n:
        return V[:n]
    for i in range(n):
        for j in range(r, len(V)):
            if V[j] & (1<<i):
                (V[r], V[j]) = (V[j], V[r])
                for k in range(max(pre, r+1), len(V)):
                    if V[k] & (1<<i):
                        V[k] ^= V[r]
                r += 1
                break
    return V[:r]

B = [[]]
for X in range(1, 1<<n):
    for j in range(n):
        if X & (1<<j):
            B.append(elim(B[X ^ (1<<j)] + S[j], len(B[X ^ (1<<j)])))
            break

dst = [1<<20]*(n*(1<<n))
targ = len(B[(1<<n)-1])
Q = []
Q.append((1<<n) | (1<<1))
dst[Q[0]] = 1
qh = 0
while qh < len(Q):
    X = Q[qh]
    u = X >> n
    F = X & ((1<<n)-1)
    qh += 1
    for v in adj[u]:
        Y = (v << n) | F | (1 << v)
        if dst[Y] == 1<<20:
            Q.append(Y)
            dst[Y] = dst[X] + 1
            if not v and len(B[Y]) == targ:
                print(dst[Y])
                import sys
                sys.exit(0)
