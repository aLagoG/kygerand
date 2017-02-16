def isCoast(i, j):
	#up
	if(i >= 0):
		if picture[i-1][j] == '-': return True
	#down
	if(i < n):
		if picture[i+1][j] == '-': return True
	#left
	if(j != 0):
		if picture[i][j-1] == '-': return True
	#right
	if(j < m):
		if picture[i][j+1] == '-': return True

	return False


n, m = [int(k) for k in raw_input().split()]
picture = [raw_input() for i in xrange(n)]

count = 0
for i in xrange(n):
	for j in xrange(m):
		if picture[i][j] == '+':
			if isCoast(i, j):
				count += 1
print count
