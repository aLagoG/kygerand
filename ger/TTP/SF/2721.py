input()
cards = [int(i) for i in raw_input().split()]

while True:
	cards.sort()
	cur = cards[0]
	found = False
	for i in cards:
		if i > cur: found = True
	if not found: break

	for i in xrange(1, len(cards)):
		if cards[i] > cur:
			if cards[i]%cur == 0:
				cards[i] = cur
			else:
				cards[i] = cards[i]%cur



print sum(cards)