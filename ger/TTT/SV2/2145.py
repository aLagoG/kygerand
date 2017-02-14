for i in xrange(input()):
	scores = [int(j) for j in raw_input().split()]
	scores.sort()
	c = 0
	for j in range(1,9): c+=scores[j]
	toret = str(i+1) + " " + str(c)
	print toret