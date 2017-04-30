def nxt(i): return 0 if i == n-1 else i+1

def prev(i): return n-1 if i == 0 else i-1

for t in xrange(input()):
	
	flipped = 0
	line = [int(i) for i in raw_input().split()]
	n = line[0]

	line = line[1:]
	one = 0
	for i in xrange(n):
		if line[i] == 1:
			if line[prev(i)] == 2:
				one = prev(i)
			elif line[nxt(i)] == n:
				one = nxt(i)
			else:
				one = i
	i = one
	true = 1
	while True:
		if line[i] != true: flipped += 1
		i = nxt(i)
		true += 1
		if i == one: break

	print flipped