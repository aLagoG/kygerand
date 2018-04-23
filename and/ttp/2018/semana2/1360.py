#!/usr/bin/env python2

while True:
    p,q = (int(x) for x in raw_input().split())
    if p == 0 == q:
        break
    res = []
    op,oq = p,q
    while True:
        if p % q == 0:
            res.extend([p//q-1, 1])
            break
        res.append(p//q)
        p,q = q,p%q
    print "{}/{}=[{}]".format(op,oq,','.join([str(x) for x in res]))

