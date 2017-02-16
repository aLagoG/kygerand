years = [0]*2016 
for t in xrange(input()):
	year, reports = [int(i) for i in raw_input().split()]
	if years[year] != 0:
		years[year] += reports
	else:
		years[year] = reports
for i in range(len(years)):
	if years[i] != 0:
		print i, years[i]