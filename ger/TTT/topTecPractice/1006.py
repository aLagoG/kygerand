def switcheroo(line, start, end):
	if start >= end : return
	print line[((end+1)/2)-1]
	switcheroo(line, start, ((end+1)/2)-1)
	switcheroo(line, ((end+1)/2)+1, end)


line = "fcabdeighjk"
switcheroo(line, 0, len(line)+1)

