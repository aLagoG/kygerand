#!/usr/bin/env python
import math

total = 0

for i in range(int(input()[:-1])):
    r, tp, side = [int(x) for x in input()[:-1].split(",")]
    if side == 0:
        total += 1
        continue

    if tp == 4:
        if 2 * (side**2) <= (2 * r)**2:
            total += 1
    elif tp == 3:
        min_r = side / math.sqrt(3)
        if r >= min_r:
            total += 1
print(total)
