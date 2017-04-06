a = [int(i) for i in raw_input().split(":")]
b = [int(i) for i in raw_input().split(":")]
a[0] *= 3600
a[1] *= 60
b[0] *= 3600
b[1] *= 60
diff = sum(a) - sum(b)

hours = diff/3600
if(hours < 0): hours = 24-(hours*-1)

minutes = (diff%3600)/60
print diff, (diff%3600), (diff%3600)/60
# print hours, minutes
print "%02d:%02d" % (hours, minutes)