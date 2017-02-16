a = int(raw_input())
b = int(raw_input())
c = int(raw_input())
if(a+b+c != 180): print "Error"
elif((a == 60) and (a == 60) and (b == 60)): print "Equilateral"
elif((a != b) and (a != c) and (b != c)): print "Scalene" 
else: print "Isosceles"