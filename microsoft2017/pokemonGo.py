#!/usr/bin/env python

n, t, k = [int(x) for x in input().split()]
stops = []
totalDist = 0
dists = []
for i in range(n):
    stops.append([int(x) for x in input().split()])
    if i > 0:
        dists.append(sum([abs(stops[i - 1][j] - stops[i][j])
                          for j in range(2)]))
print(" ".join([str(x) for x in dists]))
