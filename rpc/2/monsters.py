#!/usr/bin/env python
while 1:
    try:
        n = int(input())
        lst = [int(x) for x in input().split()]
    except:
        break
    # ind = {x: i for i, x in enumerate(lst)}
    cnt = 0
    for i in range(n):
        while i + 1 != lst[i]:
            idx = lst[i] - 1
            lst[i], lst[idx] = lst[idx], lst[i]
            cnt += 1
    print(cnt)