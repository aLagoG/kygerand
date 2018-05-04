while 1:
    try:
        if int(input(), 16) % 17 == 0:
            print('yes')
        else:
            print('no')
    except:
        break