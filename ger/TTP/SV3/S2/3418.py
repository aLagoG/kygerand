text = raw_input()
vow = [0, 0, 0, 0, 0]
for i in text:
	if i == 'A' or i == 'a': vow[0] += 1
	if i == 'E' or i == 'e': vow[1] += 1
	if i == 'I' or i == 'i': vow[2] += 1
	if i == 'O' or i == 'o': vow[3] += 1
	if i == 'U' or i == 'u': vow[4] += 1

vow = [str(i) for i in vow]
print " ".join(vow)