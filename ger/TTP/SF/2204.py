for t in xrange(input()):
	n = input()
	toret = [int(i) for i in range(1,n+1)]
	toret[0], toret[len(toret)-1] = toret[len(toret)-1], toret[0]
	print " ".join(map(str,toret))