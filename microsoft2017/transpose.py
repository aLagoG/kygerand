#!/usr/bin/env python

try:
    arr = []
    while(1):
        line = input().split()
        arr.append(line)
except:
    pass

for line in zip(*arr):
    print(" ".join(line))