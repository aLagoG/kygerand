import itertools
def score(perm):

	total = 0

	rep = 1
	for i in range(1, len(perm)):
		if perm[i] == perm[i-1]:
			rep += 1
		else:
			if perm [i-1] == '0':
				total += rep**2
			else:
				total -= rep**2
			rep = 1

	if perm[len(perm)-1] == '0':
		total += rep**2
	else: 
		total -= rep**2
	return total


perstr = ""
n = input("0's >")
k = input("1's >")
for i in range(n): perstr+="0"
for i in range(k): perstr+="1"
s = set("")
for i in  itertools.permutations(perstr,n+k): s.add("".join(i))
superset = [[i, score(i)] for i in s]
for i in sorted(superset, key=lambda x: x[1], reverse=True):
	print i


