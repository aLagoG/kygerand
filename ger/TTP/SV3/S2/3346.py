import bisect
totalBells, budget = [int(i) for i in raw_input().split()]
bells = [int(i) for i in raw_input().split()]
totalSellers = input()
sellers = [int(i) for i in raw_input().split()]
bells.sort()
for price in sellers:
	maxBell = budget/price
	print totalBells - bisect.bisect_right(bells, maxBell)

	
