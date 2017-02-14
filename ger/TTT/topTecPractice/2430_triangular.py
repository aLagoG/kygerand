import math

i = 0
top = 160000000000000000000
n = 0
while n <= top:
	n = (i*(i+1))/2
	#if n == 0: break
	if math.sqrt(1+(8.0*n)).is_integer(): print n
	else: 
		print "NO"
		break
	i+=1