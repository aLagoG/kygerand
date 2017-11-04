#!/usr/bin/env python
while 1:
    try:
        n, t = input().split()
    except:
        break
    n = int(n)
    if t == 'R' or t == 'B':
        print(n)
    elif t == 'K':
        print(min(n, 2))
    elif t == 'N':
        if n < 3:
            print(1)
        else:
            print(min(n, 2))
