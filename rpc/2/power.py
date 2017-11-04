#!/usr/bin/env python
from collections import defaultdict

def search(x,y,do):
    if x not in plane or y not in plane[x]:
        return 0
    if x in visited and y in visited[x]:
        return 0
    visited[x].add(y)
    r = 1 if do else 0
    r += search(x,y+1,not do)
    r += search(x+1,y,not do)
    r += search(x,y-1,not do)
    r += search(x-1,y,not do) 
    return r

while 1:
    try:
        n = int(input())
    except:
        break
    plane = defaultdict(set)
    first = [0,0]
    for i in range(n):
        point = [int(x) for x in input().split()]
        plane[point[0]].add(point[1])
        if i ==0:
            first = point[:]
    visited = defaultdict(set)
    print(plane)
    print(first)
    print(max(search(first[0],first[1], True),search(first[0],first[1], False)))