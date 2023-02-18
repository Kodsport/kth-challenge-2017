#!/usr/bin/env python3
import math
import sys
sys.setrecursionlimit(10000)

n, m, k = map(int, input().split())
I = [list(map(int, input().split())) for _ in range(n)]

adj = [[0]*n for _ in range(n)]
dst = [0]*n
for _ in range(m):
    x, y, h = map(int, input().split())
    src = 0
    dsts = 0
    for i in range(n):
        xx, yy, r = I[i]
        if (x-xx)**2 + (y-yy)**2 < r**2:
            src = i
        elif (x-xx)**2 + (y-yy)**2 <= (r+h*k)**2:
            dst[dsts] = i
            dsts += 1
    for d in range(dsts):
        adj[src][dst[d]] = 1

order = []
def topsort(u, vis):
    vis[u] = True
    for v in range(n):
        if adj[u][v] and not vis[v]:
            topsort(v, vis)
    order.append(u)

def build(u, root, roots):
    roots[u] = root
    for v in range(n):
        if adj[v][u] and roots[v] < 0:
            build(v, root, roots)

vis = [False]*n
for i in range(n):
    if not vis[i]:
        topsort(i, vis)

root = [-1]*n
for u in reversed(order):
    if root[u] < 0:
        build(u, u, root)

src = [True]*n
sink = [True]*n
for i in range(n):
    for j in range(n):
        if root[j] != root[i]:
            if adj[i][j]:
                sink[root[i]] = False
            if adj[j][i]:
                src[root[i]] = False

Crit = [i for i in range(n) if root[i] == i and (src[i] or sink[i])]

if len(Crit) > 2:
    print('impossible')
elif len(Crit) < 2:
    print('0')
else:
    (u, v) = list(Crit)
    res = min(math.sqrt((I[i][0]-I[j][0])**2 + (I[i][1]-I[j][1])**2) - I[i][2] - I[j][2] + 100 + 100
              for i in range(n) if root[i] == u
              for j in range(n) if root[j] == v)
    print(res)
