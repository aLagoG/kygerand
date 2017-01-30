import math
while 1:
	n = input()
	if n == 0: break
	if math.sqrt(1+(8.0*n)).is_integer():
		print "YES"
	else:
		print "NO"
