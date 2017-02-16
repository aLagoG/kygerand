for i in xrange(input()):
	scores = [int(i) for i in raw_input().split()]
	scores.sort()
	c = 0
	for i in range(1,9): c+=i
	print c