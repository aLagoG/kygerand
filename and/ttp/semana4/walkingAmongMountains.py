n = input();
mp = [[int(i) for i in raw_input()] for j in xrange(n)]
pnt = [[0 for i in xrange(n)] for j in xrange(n)]
x, y = [int(i) for i in raw_input().split()]

for i in xrange(1,x):
	pnt[0][i] =  pnt[0][i-1]+mp[0][i]-mp[0][i-1] if mp[0][i]>mp[0][i-1] else pnt[0][i-1]
for i in xrange(1,y):
	pnt[i][0] = pnt[i-1][0]+mp[i][0]-mp[i-1][0] if mp[i][0]>mp[i-1][0] else pnt[i-1][0]
t = 0
l = 0
for i in xrange(1,y):
	for j in xrange(1,x):
		t = pnt[i-1][j]+mp[i][j]-mp[i-1][j] if mp[i][j]>mp[i-1][j] else pnt[i-1][j];
		l = pnt[i][j-1]+mp[i][j]-mp[i][j-1] if mp[i][j]>mp[i][j-1] else pnt[i][j-1];
		pnt[i][j] = l if t>l else t;
print pnt[y-1][x-1]