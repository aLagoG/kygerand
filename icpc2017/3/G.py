for t in range(int(input())):
    line = [int(n) for n in input().split(" ")]
    mx = max(line)
    cnt = 0
    flag = False
    for item in line:
        if flag:
            if item == mx:
                flag = False
            cnt += 1
        else:
            if item == mx:
                flag = True
                cnt += 1
    print(cnt)
