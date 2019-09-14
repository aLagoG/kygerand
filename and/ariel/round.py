n, k = [ int(i) for i in input().split() ]

racers = [ int(i) for i in input().split() ]

kth_score = sorted(racers, reverse = True)[k - 1]

print(
    len(
        list(filter(
            lambda x: x > 0 and x >= kth_score,
            racers
        ))
    )
)
