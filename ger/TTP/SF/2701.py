word = sum([ord(i)-64 for i in raw_input().rstrip("\n")])
w1, w2 = "", ""

half1 = word - word/2
half2 = word - (word - word/2)

c = half1
while(half1>0):
	if half1-min(c, 26) >= 0:
		add = min(c, 26)
		w1 += chr(add+64)
		half1 -= add
	c -= 1

c = half2
while(half2>0):
	if half2-min(c,26) >= 0:
		add = min(c, 26)
		w2 += chr(add+64)
		half2 -= add
	c -= 1
print w2, w1