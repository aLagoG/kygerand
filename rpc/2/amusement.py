#!/usr/bin/env python
while 1:
    try:
        n = int(input())
        lst = [int(x) for x in input().split()]
    except:
        break
    if n == 1:
        print(1)
        continue

    dst = lst[-1] - lst[-2]
    res = 1
    for i in range(n - 3, -1, -1):
        if lst[i + 1] - lst[i] != dst:
            res = i + 2
            break

    print(res)
