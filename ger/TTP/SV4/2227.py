
def search(i, j):


n = input()
mapp = [[] for i in xrange(n)]
for i in xrange(n):
	mapp[i] = [int(j) for j in raw_input()]
jmax, imax = [int(i)-1 for i in raw_input().split()]
print search(0,0)


