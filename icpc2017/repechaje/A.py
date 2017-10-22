#!/usr/bin/env python
from fractions import Fraction
try:
    while 1:
        n = int(input())
        res = Fraction(3 * n, 2 * n + 1)
        print(res)
except:
    pass
