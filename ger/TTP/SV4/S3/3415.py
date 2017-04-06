for t in xrange(input()):
	imei = [int(i) for i in list(raw_input())]
	add = 0
	for i in range(1, 14, 2):
		imei[i] *= 2
		if imei[i] > 9: imei[i] -= 9

	add = sum(imei)
	if add % 10 > 0:
		print 10 - (add %10)
	else: 
		print "0"