#!/usr/bin/env python3
INF = 10e18
n, m = map(int, input().split())
cost = [[INF for i in range(n)] for j in range(n)]

for _ in range(m):
    v,u,c = map(int, input().split())
    v, u = v-1, u-1
    cost[v][u] = c
    cost[u][v] = c

mem = {}
comp = []
def dp(left):
    if not left:
        return 0
    if left in mem:
        return mem[left]
    at = (left&-left).bit_length()-1
    res = INF
    for to in range(at+1, len(comp)):
        if not (~left & (1<<to)):
            res = min(res, cost[comp[at]][comp[to]] + dp(left ^ (1<<at) ^ (1<<to)))
    mem[left] = res
    return res
    
sm = 0
vis = [False for i in range(n)]
for i in range(n):
    if not vis[i]:
        comp = [i]
        mem.clear()
        vis[i] = True
        for j in range(n):
            if cost[i][j] != INF:
                comp.append(j)
                vis[j] = True
        if len(comp) % 2:
            print('impossible')
            break
        sm += dp((1<<len(comp))-1)
else:
    print(sm)
