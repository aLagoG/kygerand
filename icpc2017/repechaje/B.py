#!/usr/bin/env python
from collections import deque, defaultdict


def rec(c, orig, mp, line, srt, res):
    if len(res) == len(line):
        return
    # creemos que no puedes cruzar el $ cuando buscas 
    # o sea eso te dice de que lado hacer el pop
    idx = mp[c].popleft()
    res.append(srt[idx])
    rec(srt[idx],idx, mp, line, srt, res)


while 1:
    try:
        line = input()
    except:
        break
    srt = sorted(line)
    mp = defaultdict(deque)
    hack = 0
    for i, c in enumerate(line):
        if c == '$':
            hack = i
        mp[c].append(i)
    res = deque()
    rec(line[0], 0, mp, line, srt, res)
    res.popleft()
    print(''.join(res))
