n = int(input())
teams = [ ]
for _ in range(n):
    # home, guest
    teams.append([ int(i) for i in input().split() ])

overlaps = 0
for i in range(n):
    home_shirt = teams[i][0]
    for j in range(n):
        if i == j: continue

        visitor_shirt = teams[j][1]
        if home_shirt == visitor_shirt: overlaps += 1

print(overlaps)
