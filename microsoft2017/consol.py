n = 1
avrg = 0
for i in input().split(","):
    avrg += (int(i) - avrg)/n
    n += 1

print(int(round(avrg)))