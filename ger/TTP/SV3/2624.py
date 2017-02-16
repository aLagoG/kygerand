for t in xrange(input()):
	days = [int(i) for i in raw_input().split()][0]
	cities = [int(i) for i in raw_input().split()]
	cities.sort()

	daysUsed = 0
	i = 0
	while i < (len(cities)):
		if(daysUsed + cities[i]) > days: 
			break
		else:
			daysUsed += cities[i]

		i += 1
	print i