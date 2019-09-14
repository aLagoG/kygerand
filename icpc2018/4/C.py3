# def readIdx(s):
#     a, b, c = (int(x) for x in s.split('/'))
#     return a * 1000 + (b - 1) * 50 + c - 1

def readIdx(s):
    a, b, c = (int(x) for x in s.split('/'))
    res = a
    res *= 100
    res += b
    res *= 100
    res += c
    return res


n, q, mi, ma = input().split()
n, q, mi, ma = int(n), int(q), readIdx(mi), readIdx(ma)
ln = ma - mi + 1
a = [0] * ln
prev = 0
for _ in range(n):
    r, d, t = input().split()
    d, t = readIdx(d) - mi, int(t)
    for i in range(prev + 1, d):
        a[i] = a[prev]
    a[d] = a[prev] + t
    prev = d
for _ in range(q):
    q, s, e = input().split()
    s, e = readIdx(s) - mi, readIdx(e) - mi
    print(a[e] - (a[s - 1] if s > 1 else 0))
