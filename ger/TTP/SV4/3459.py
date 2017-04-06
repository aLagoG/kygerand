robots = [0, 1, 3, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False]
times = [0, 0, 8, 35, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False, False]

def rob(n):
	if robots[n]:
		return robots[n]
	robots[n] = 1+n*rob(n-1)
	return robots[n]

def time(n):
	if times[n]: return times[n]
	times[n] = n**3 + time(n-1)
	return times[n]

rob(20)
time(20)
k = input()
print times