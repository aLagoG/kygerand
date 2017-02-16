n = int(raw_input())
for i in range(n):
	line = raw_input().split(" ")
	numer = line[0]
	names = line[1:]
	toret = numer[:2]

	for i in range(len(names)-1, -1, -1):
		toret += names[i]
		if i != 0: toret += "*"
	toret += numer[2:]
	print toret