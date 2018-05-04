from math import factorial
t = int(input())
for ab in range(t):
    counts = [0] * 10
    sn = input()
    size = len(sn)
    for c in sn:
        counts[int(c)] += 1
    perms = factorial(size)
    for i in range(10):
        perms //= factorial(counts[i])
    mul = perms // size
    ds = 0
    for i in range(10):
        ds += i * counts[i] * mul
    all_sum = ds
    for cd in range(size - 1):
        ds *= 10
        all_sum += ds
    print("%d %d" % (perms, all_sum))
