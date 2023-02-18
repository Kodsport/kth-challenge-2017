#!/usr/bin/env python3
X = int(input())
add = X % 8
if 1 <= add <= 5: add = 5 - add
elif 6 <= add <= 7: add = 8 - add
print(X + add)
