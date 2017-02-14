n = input();
for i in range(n):
	line = raw_input().split(" ")
	toRet = "".join(line[0].split()[:2])
	print toRet