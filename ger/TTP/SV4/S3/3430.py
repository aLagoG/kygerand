line = list(raw_input())

i = length = len(line)-1
while i >= 0:
	if line[i] == "(":
		line.pop(i)
		a = b = i
		while True:
			if line[b] == ")": 
				line.pop(b)
				b -= 1
				break
			b += 1
		line[a:b+1] = reversed(line[a:b+1])
	i -= 1

print "".join(line)