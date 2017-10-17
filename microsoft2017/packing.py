#!/usr/bin/env python

sp, remove_empty = input().strip().split(":")
remove_empty = remove_empty == "True"
sp = int(sp)
orig_count = 0
empty_count = 0
import math
inNode = False
input()
lines = []
while(1):
    line = input().strip()
    if not inNode and line == "[":
        orig_count += 1
        inNode = True
        continue
    if not inNode and line == ']':
        break
    if inNode and line == ']':
        inNode = False
        continue
    if line == '':
        empty_count += 1
        if not remove_empty:
            lines.append(line)
    else:
        lines.append(line)
out_count = math.ceil(len(lines) / sp)
diff = out_count - orig_count
out_empty = (empty_count if not remove_empty else 0) + out_count * sp - len(lines)
diff_empty = out_empty - empty_count
print(out_count)
print(diff)
print(diff_empty)
print(out_empty)
print("[")
for i in range(out_count):
    print("[")
    for j in range(sp):
        if i * sp + j < len(lines):
            print(lines[i * sp + j])
        else:
            print()
    print("]")
print("]")
