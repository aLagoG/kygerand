chapters = range(1,input()+1)
fillers = [int(i) for i in raw_input().split()]
del fillers[0]
for i in fillers:
	try:chapters.remove(i)
	except:pass
print len(chapters)