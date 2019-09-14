m = []
for _ in range(5):
    m.append( list(map(int, input().split())) )

i, j = 0, 0
for idx, row in enumerate(m):
    if 1 in row:
        i = idx
        j = row.index(1)
        break

print(abs(i-2) + abs(j-2))
