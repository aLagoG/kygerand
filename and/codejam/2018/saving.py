from math import ceil

t = int(input())
for i in range(1, t + 1):
    p, s = input().split()
    p = int(p)
    v = 1
    ac = 0
    mp = []
    for idx, c in enumerate(s):
        if c == 'C':
            mp.append([idx, v, 0])
            v <<= 1
        else:
            ac += v
            if v > 1:
                mp[-1][-1] += 1
    swaps = 0
    while ac > p and len(mp) > 0:
        dif = ac - p
        m = ceil(dif / mp[-1][1])
        if m > mp[-1][-1]:
            ac -= mp[-1][-1] * mp[-1][1]
            m = mp[-1][-1]
        else:
            ac -= mp[-1][1] * m
        swaps += m
        mp.pop()
        if len(mp) >= 1:
            mp[-1][-1] += m
    print('Case #' + str(i) + ': ', end='')
    if ac > p:
        print('IMPOSSIBLE')
    else:
        print(swaps)