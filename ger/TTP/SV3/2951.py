unique = set()
for t in xrange(input()): unique.add(tuple(sorted([i for i in raw_input()])))
print len(unique)