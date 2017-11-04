from bisect import bisect_right
n = int(input())
pirates = sorted([int(i) for i in input().split(" ")])
chests = sorted([int(i) for i in input().split(" ")])

tot = 1
for i in range(n):

    count = bisect_right(pirates, chests[i], lo=i) - i

    if count == 0:
        tot = 0
        break
    else:
        tot *= count
        tot %= 1000000007

print(tot)
