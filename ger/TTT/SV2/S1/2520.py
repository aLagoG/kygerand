for test in xrange(input()):
	N, P, J, F = [int(i) for i in raw_input().split()]
	al = [str(i) for i in range(1,N+1)]
	seen = [str(i) for i in range(1, P+1)]
	
 	recorded = [i for i in raw_input().split()]
	fillers = [i for i in raw_input().split()]

	#non-fillers que no fueron grabados y no ha visto (numero e ids)
	first = []

	for episode in al:
		if episode not in seen and episode not in recorded and episode not in fillers: first.append(episode)
	
	first = [int(i) for i in first]
	first.sort()
	first = [str(i) for i in first]

	print str(len(first)) + " " + " ".join(first)

	#grabados que se deben de borrar (porque ya los vio o son fillers)
	second = []
	for episode in recorded:
		if episode in seen or episode in fillers: second.append(episode)

	second = [int(i) for i in second]
	second.sort()
	second = [str(i) for i in second]
	
	print str(len(second)) + " " + " ".join(second)