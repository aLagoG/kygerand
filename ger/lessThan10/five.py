from operator import itemgetter
dates = []
for n in range(input()): dates.append([int(i) for i in raw_input().split()])
for i in xrange(3):
	dates.sort(key = itemgetter(i))
	print dates