from collections import defaultdict

s = defaultdict(int)
n = input()
for _ in range(n):
    x = sorted(raw_input().split())
    s[' '.join(x)] += 1
print(max(s.values()))
