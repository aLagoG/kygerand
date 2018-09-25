n, m = [int(x) for x in input().split()]

l, *b = [int(x) for x in input().split()]
orig = 0
for t in b:
    orig |= 1<<(t-1)
current = 0
answer = -1
readings = []
lines = [set() for _ in range(n)]
for t in range(n):
    l, *b = [int(x) for x in input().split()]
    reading = 0
    for x in b:
        reading |= 1<<(x-1)
    readings.append(reading)
    current ^= reading
    if current ^ orig == 0:
        answer = t+1
        break
    else:
        lines[t].add(current)
    
if answer == -1:
    def fn():
        global current
        loops = 0
        while True:
            loops += 1
            for i in range(n):
                current ^= readings[i]
                if current ^ orig == 0:
                    return i + 1 + loops*n
                if current in lines[i]:
                    return -1
                else:
                    lines[i].add(current)
    answer = fn()
                
print("%d" % answer)