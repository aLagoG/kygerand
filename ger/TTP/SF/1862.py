def F(x):
	return a*(x**4)+b*(x**3)+c*(x**2)+d*(x)+e-f

while True:
	try:
		a, b, c, d, e, f = [int(i) for i in raw_input().split()]

		start = -10.0**70
		end = 10.0**70

		last = -1
		spec = False
		while True:

			if(end-start == 1 and F(end)!= 0 and F(start) != 0):
				spec = True
				break

			mid = (start+end)/2.0

			if F(mid) == 0: break
			if last == mid: break
			
			if F(mid) > 0:
				end = mid
			else:
				start = mid

			last = mid

		if spec or mid < 0: print "-1"
		else: print int(mid)



	except EOFError: break