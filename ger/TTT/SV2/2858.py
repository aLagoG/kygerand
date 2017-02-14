line = raw_input()
toret = ""
i = 0
while i < len(line):
	if line[i] == '1' or line[i] == '0':
		binary = ""
		while i<len(line) and (line[i] == '1' or line[i] == '0'):
			binary += line[i]
			i += 1
		toret += str(int(binary,2)%1000000007)
	else:
		toret+= line[i]
		i += 1
print toret