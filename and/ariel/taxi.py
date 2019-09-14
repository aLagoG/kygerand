input()
groups = sorted([ int(i) for i in input().split() ], reverse=True)

cars = 0

i = 0
j = len(groups) - 1
while i <= j:
    g = groups[i]
    if g == 4:
        i += 1
        cars += 1
        continue

    cur_car = g
    while groups[j] <= 4 - cur_car and i < j:
        cur_car += groups[j]
        j -= 1

    i += 1
    cars += 1



print(cars)


