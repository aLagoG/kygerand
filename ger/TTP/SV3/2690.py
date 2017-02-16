rows1, cols1 = [int(i) for i in raw_input().split()]
matrix1 = [[0]*cols1]*rows1
for i in xrange(rows1):
	matrix1[i] = [int(r) for r in raw_input().split()]


rows2, cols2 = [int(i) for i in raw_input().split()]
matrix2 = [[0]*cols2]*rows2
for i in xrange(rows2):
	matrix2[i] = [int(r) for r in raw_input().split()]

if cols1 == rows2:
	mr = [[0 for i in xrange(cols2)] for j in xrange(rows1)]

	for i in xrange(rows1):
		for j in xrange(cols2):
			for k in xrange(cols1):
				mr[i][j] += matrix1[i][k] * matrix2[k][j]
			mr[i][j] = str(mr[i][j])


	for row in mr:
		print " ".join(row)
			
else:
	print "The matrices can not be multiplied"
