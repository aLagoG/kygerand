import math
c = []
for i in xrange(input()):
	c.append(input())
c.sort(reverse=True)
summ = 0
for i in range(10):
	summ += c[i]
print "%.4f" % (summ/(2*math.pi))