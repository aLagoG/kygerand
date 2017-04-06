awords = {}
for t in xrange(input()):
	strword = "".join(sorted(raw_input()))
	if strword in awords:
		awords[strword] += 1
	else:
		awords[strword] = 0
	print awords[strword]