n, k = [ int(i) for i in input().split() ]
geeks = sorted([ int(i) for i in input().split() ])

part = n
for i, geek in enumerate(geeks):
    if geek > 5 - k:
        part = i
        break


#print( part )
print( part // 3 )
