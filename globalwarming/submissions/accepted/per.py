#!/usr/bin/env python3
(n, m) = map(int, input().split())

C = [[-1]*n for _ in range(n)]
for _ in range(m):
    (p, q, c) = map(int, input().split())
    C[p-1][q-1] = C[q-1][p-1] = c


def search(S):
    s = len(S)
    ans = [1<<30]*(1<<s)
    def rec(M):
        if M == 0: return 0
        if ans[M] != 1<<30: return ans[M]
        for i in range(s):
            if M & (1<<i):
                ans[M] = min(rec(M ^ (1<<j) ^ (1<<i)) + C[S[i]][S[j]] for j in range(i+1, s) if M & (1<<j))
                break
        return ans[M]
    return rec((1<<s)-1)

def solve():
    ans = 0
    for u in range(n):
        S = [v for v in range(n) if v == u or C[u][v] != -1]
        if S[0] != u: continue
        if len(S) % 2: return 'impossible'
        ans += search(S)
    return ans

print(solve())
