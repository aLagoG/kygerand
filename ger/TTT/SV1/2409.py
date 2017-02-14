name = raw_input()
numbers = [int(i) for i in raw_input().split(" ")]
index = abs(numbers[0]-numbers[1])
print name + " " + str(index)