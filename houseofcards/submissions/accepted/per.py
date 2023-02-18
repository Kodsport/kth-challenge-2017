#!/usr/bin/env python3

h0 = int(input())
while (3*h0*h0 + h0)//2 % 4: h0 += 1
print(h0)
