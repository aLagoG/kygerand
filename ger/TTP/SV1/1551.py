j = 1
while 1:
	try:
		line = raw_input()
		a, b, c = [int(i) for i in line.split()]
		if(a+b == c): print "Case "+str(j) + ": "+str(a)+"+"+str(b)+"="+str(c)
		elif(a == b+c): print "Case "+str(j) + ": "+str(a)+"="+str(b)+"+"+str(c)
		elif(a-b == c): print "Case "+str(j) + ": "+str(a)+"-"+str(b)+"="+str(c)
		elif(a == b-c): print "Case "+str(j) + ": "+str(a)+"="+str(b)+"-"+str(c)
		elif(a*b == c): print "Case "+str(j) + ": "+str(a)+"*"+str(b)+"="+str(c)
		elif(a == b*c): print "Case "+str(j) + ": "+str(a)+"="+str(b)+"*"+str(c)
		elif(a/b == c): print "Case "+str(j) + ": "+str(a)+"/"+str(b)+"="+str(c)
		elif(a == b/c): print "Case "+str(j) + ": "+str(a)+"="+str(b)+"/"+str(c)
		j += 1
	except EOFError: break