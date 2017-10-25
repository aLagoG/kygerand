from collections import deque, defaultdict

def B(s):
    def rec(c, mp, line, srt, res):
        if len(res) == len(line):
            return
        idx = mp[c].popleft()
        res.append(srt[idx])
        rec(srt[idx], mp, line, srt, res)

    line = s
    srt = ''.join(sorted(line))
    mp = defaultdict(deque)
    for i, c in enumerate(line):
        mp[c].append(i)
    res = deque()
    rec(line[0], mp, line, srt, res)
    res.popleft()
    return ''.join(res)

line = input()+'$'
que = deque()
arr = []
for i in line:
    que.append(i)

for i in range(len(line)):
    que.rotate(1)
    arr.append(''.join(que))

topr = []
for c in sorted(arr):
    topr.append(c[-1])
print(''.join(topr))
print(B(''.join(topr)))
