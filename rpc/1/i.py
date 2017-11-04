import math
from collections import *

def angle(p0,p1,c):
    p0c = math.sqrt( (c[0]-p0[0])**2 +  (c[1]-p0[1])**2 )
    p1c = math.sqrt( (c[0]-p1[0])**2 +  (c[1]-p1[1])**2 )
    p0p1 = math.sqrt( (p1[0]-p0[0])**2 + (p1[1]-p0[1])**2 )

    return round(math.acos( (p1c**2+p0c**2-p0p1**2) / (2*p1c*p0c)),8)

def prev(i): return i - 1 if i > 0 else v - 1
def next(i): return i + 1 if i < v - 1 else 0

v = int(input())
a, aAngles = [ [int(i) for i in input().split(" ")] for j in range(v) ], deque([angle(a[prev(i)], a[i], a[next(i)]) for i in range(v)])
b, bAngles = [ [int(i) for i in input().split(" ")] for j in range(v) ], deque([angle(b[prev(i)], b[i], b[next(i)]) for i in range(v)])

eq = True
try:
    bAngles.rotate(aAngles.index(bAngles[0]))
except ValueError:
    eq = False

if eq:
    for i in range(v):
        if aAngles != bAngles:
            eq = False
            break

print("MISMO" if eq else "OTRO")