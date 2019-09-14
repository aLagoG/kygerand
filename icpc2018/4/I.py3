n = [int(x) for x in input().split('.')]
print("".join(["{0:08b}".format(x) for x in n]))