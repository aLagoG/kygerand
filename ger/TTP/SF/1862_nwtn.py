from math import sqrt
def F(x): return a*(x**4)+b*(x**3)+c*(x**2)+d*(x)+e-f
def D(x): return 4*a*(x**3) + 3*b*(x**2) + 2*c*(x) + d


while 1:
	try:

		a, b, c, d, e, f = [int(i) for i in raw_input().split()]
		init = sqrt(sqrt(f-e))
		last = -1
		c = 0
		while 1:
			init -= F(init)/D(init)
			print init
			
			last = init
			c += 1

			
		print int(init), c







	except EOFError: break