from fractions import Fraction
t = 1
while t:
	v1, d1, v2, d2 = [int(i) for i in raw_input().split()]
	if v1 == d1 == v2 == d2 == 0: break
	myTime = Fraction(d1, v1)
	hisTime = Fraction(d2, v2)
	if myTime < hisTime:
		print "Case #" + str(t) + ": You owe me a beer!"
	else:
		print "Case #" + str(t) + ": No beer for the captain."
	print "Avg. arrival time:",((myTime + hisTime)/2)

	t += 1
