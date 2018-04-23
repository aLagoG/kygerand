#!/usr/bin/env python2
import math

while True:
    n = 0
    try:
        n = input()
    except:
        break
    cnt = 0
    while n>0:
        f = math.floor((-1+math.sqrt(1+8*n))/2)
        n-=(f*(f+1))/2
        cnt+=1
    print cnt