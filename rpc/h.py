#!/usr/bin/env python
num = int(input())
heights = [0] + [int(x) for x in input().split()] + [0]
cnt = 0
up = heights[0] < heights[1]
for i in range(num + 1):
    if up and heights[i] > heights[i + 1]:
        cnt += 1
        up = False
    if not up and heights[i] < heights[i + 1]:
        # cnt += 1
        up = True
print(cnt)
