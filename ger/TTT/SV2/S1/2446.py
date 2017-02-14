def scoreBianka(inp):
	if inp == "WWW": return 2
	if inp == "BBB": return 0
	if inp.count("B") == 2 or inp.count("W") == 2: return 1

def scoreWilliams(inp):
	if inp == "WWW": return 2
	if inp == "BBB": return 0
	if inp.count("B") == 2: return 0
	if inp.count("W") == 2: return 2

def winner(bianka, williams):
	if bianka == 0:
		if williams == 1: return "Williams"
		if williams == 2: return "Bianka"
	if bianka == 1:
		if williams == 0: return "Bianka"
		if williams == 2: return "Williams"
	if bianka == 2:
		if williams == 0: return "Williams"
		if williams == 1: return "Bianka"


game = {0 : "Rock",
		 1 : "Paper", 
		 2 : "Scissors"}

bianka, williams = raw_input().split()

bianka = scoreBianka(bianka)
williams = scoreWilliams(williams)

win = winner(bianka, williams)

if win == "Bianka":
	print  "Bianka won with " + game[bianka]
	print "Williams lost with " + game[williams]
else:
	print  "Williams won with " + game[williams]
	print "Bianka lost with " + game[bianka]
