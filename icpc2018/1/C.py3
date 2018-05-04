from functools import reduce

wlen = 10
base = 26
bpow = base**(wlen - 1)


def invc(c):
    return 'A' if c == 'T' else 'T'


def invs(s):
    return [invc(c) for c in s]


def cleanc(c):
    return c != 'G' and c != 'C'


for _ in range(int(input())):

    bigstr = input()
    if len(bigstr) < wlen:
        print(0)
        continue

    start = 0
    clean = 0
    for i in range(len(bigstr)):
        if clean == 10:
            start = i - 10
            break
        if (cleanc(bigstr[i])):
            clean += 1
        else:
            clean = 0

    if clean < 10:
        print(0)
        continue

    cnt = 0
    seen = set()

    window_hash = reduce(lambda curhash, c: curhash * base + ord(c),
                         bigstr[start:start + wlen], 0)
    inv_hash = reduce(lambda curhash, c: curhash * base + ord(invc(c)),
                      bigstr[start:start + wlen], 0)
    seen.add(window_hash)

    for i in range(start, len(bigstr) - wlen):
        incoming, outgoing = bigstr[i + wlen], bigstr[i]

        window_hash -= ord(outgoing) * bpow
        window_hash = window_hash * base + ord(incoming)

        inv_hash -= ord(invc(outgoing)) * bpow
        inv_hash = inv_hash * base + ord(invc(incoming))

        if not cleanc(incoming):
            clean = 0
        else:
            clean += 1

        if clean >= 10:
            if inv_hash in seen:
                cnt += 2
            else:
                seen.add(window_hash)

    print(cnt)