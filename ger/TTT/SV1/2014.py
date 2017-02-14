case = 1
for i in xrange(input()):
	line = raw_input().split()
	distance = int(line[1])
	old  = [int(i) for i in line[0]]
	new = [i for i in old]

	flipped = 0

	for i in range(len(new)):
		if flipped == distance:
			break

		if new[i] == 1:
			new[i] = 0
			flipped = flipped + 1


	for i in range(len(new)-1,-1,-1):

		if flipped == distance: break
		if old[i] == 0:
			new[i] = 1
			flipped = flipped + 1

	

	endstr = ""
	for i in new:
		endstr+=str(i)
	print "Case #" + str(case) +": "+ endstr
	case += 1