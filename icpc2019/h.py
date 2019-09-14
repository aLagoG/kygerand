n, t =  [ int(i) for i in input().split() ]
problems = [int(i) for i in input().split() ]
problems.sort()

up, down = 0, 0
cur_t = t
for p in problems:
    if cur_t - p > 0:
        cur_t -= p
        up += 1
    else:
        break

cur_t = t
for p in reversed(problems):
    if cur_t - p > 0:
        cur_t -= p
        down += 1


print( down, up )
