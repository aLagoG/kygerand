def placeSafe(row, column):
	for place in placed:
		if column == place[1] or row + column == place[0] + place[1] or row - column == place[0] - place[1]:
			return False
	return True

def printer():
	global total
	toRet = "" + str(total) + " :"
	for i in placed:
		toRet += " " + str(i[1]+1)
	print toRet
	total += 1

def queenSearch(row):
	if row >= n: 
		printer()
		return True
	flag = False
	for column in xrange(n):
	
		if placeSafe(row, column): 

			placed.append([row, column])

			if queenSearch(row+1): 
				flag = True

			placed.pop()
	if flag: return True
	return False

while 1:
	try:
		n = input()
	except EOFError: break
	if n == 1: 
		print "1 : 1"
	elif n == 2 or n == 3:
		print "No Solution."
	else:
		total = 1
		for c in xrange(n):
			placed = []
			
			placed.append([0, c])
			r = 1
			queenSearch(r)