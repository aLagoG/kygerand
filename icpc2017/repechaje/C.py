#!/usr/bin/env python
facts = [1]
for i in range(1, 101):
    facts.append(facts[i - 1] * i)


def ncr(a, b):
    if b == 0 or b == a:
        return 1
    return facts[a] // (facts[b] * facts[a - b])


for t in range(int(input())):
    n = int(input())
    if n == 0:
        print(1)
        continue
    for i in range(n):
        co = ncr(n, i)
        x = 'x' if n - i == 1 else 'x^{}'.format(n - i)
        y = '' if i == 0 else 'y' if i == 1 else 'y^{}'.format(i)
        tp = ''
        if co == 1:
            tp = x + y
        else:
            tp = str(co) + x + y
        print(tp, end='+')
    print('y' if n == 1 else 'y^{}'.format(n))
