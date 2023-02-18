import sys
import re

line = sys.stdin.readline()
assert re.match('^[1-9][0-9]* (0|[1-9][0-9]*)\n$', line)

n, k = map(int, line.strip().split())
assert 1 <= n <= 200
assert 0 <= k <= 250

conn = [ [ False for j in range(n) ] for i in range(n) ]
for i in range(k):
    line = sys.stdin.readline()
    assert re.match('^[1-9][0-9]* [1-9][0-9]* (0|[1-9][0-9]*)\n$', line)
    a, b, c = map(int, line.strip().split())
    assert 1 <= a <= n
    assert 1 <= b <= n
    assert 0 <= c <= 10**6
    assert a != b

    assert not conn[a-1][b-1]
    assert not conn[b-1][a-1]

    conn[a-1][b-1] = True
    conn[b-1][a-1] = True

for i in range(n):
    for j in range(n):
        if i == j: continue
        for k in range(n):
            if i == k: continue
            if j == k: continue
            if conn[i][j] and conn[j][k]:
                assert conn[i][k]

assert sys.stdin.read() == ''
sys.exit(42)

