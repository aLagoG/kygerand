#!/usr/bin/env python
import re
rg = re.compile(r'-?\d')
while 1:
    inp = input()
    if inp == '.':
        break
    l = inp[:-1].split(', ')
    nums = []
    words = []
    types = []
    for k in l:
        if re.match(rg, k):
            nums.append(int(k))
            types.append(True)
        else:
            words.append(k.strip())
            types.append(False)
    nums.sort(reverse=True)
    words.sort(reverse=True, key=lambda s: s.lower())
    for ty in types[:-1]:
        if ty:
            print(nums[-1], end=', ')
            nums.pop()
        else:
            print(words[-1], end=', ')
            words.pop()

    if not types[-1]:
        print(words[-1] + '.')
    else:
        print(str(nums[-1]) + '.')
