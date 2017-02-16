import math
for i in xrange(input()):
	a, b = [int(j) for j in raw_input().split()]
	#print math.ceil(b/2.0)
	if b%2 == 0:
		print a**2 - 2*((b/2)**2)
	else:
		print a**2 - ((b/2)**2 + int(math.ceil(b/2.0)**2) )