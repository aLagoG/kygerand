word = list(raw_input())
if len(word)%2 == 0:
	first = word[:(len(word)/2)]
	last = word[(len(word)/2):]
	last.reverse()
	first.reverse()
	print  "".join(first) + "".join(last)
else:
	first = word[:len(word)/2]
	last = word[((len(word)/2)+1):]
	last.reverse()
	first.reverse()
	print  "".join(first) +word[len(word)/2]+ "".join(last)