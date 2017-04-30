def read():
	toRet = [[0 for i in xrange(9)] for j in xrange(9)]
	j = 0
	for i in xrange(11):
		if i != 3 and i != 7:
			toRet[j] = map(int, raw_input().replace("|", "").replace("*", "0").split())
			j += 1
		else: raw_input()

	return toRet

def write(arr):
	j = 0
	for i in xrange(11):
		if i != 3 and i != 7:
			print " ".join(map(str,arr[j][:3])) + " | " +  " ".join(map(str,(arr[j][3:6]))) + " | " + " ".join(map(str,(arr[j][-3:])))
			j += 1
		else:
			print "------+-------+------"

def locationsInit(board):
	toRet = []
	for i in xrange(9):
		for j in xrange(9):
			if board[i][j] == 0: 
				toRet.append([i,j])
			else:
				rows[i][board[i][j]] = True
				columns[j][board[i][j]] = True

	toRet.reverse()
	return toRet

def nextLocation(): return locations[len(locations)-1] if len(locations) != 0 else False

def validMove(board, square, number):
	row, column = square
	if rows[row][number] or columns[column][number]: return False 

	row -= row%3
	column -= column%3
	for i in xrange(3):
		for j in xrange(3):
			if board[i+row][j+column] == number:
				return False
	return True

def put(board, square, number):
	row, column = square
	rows[row][number] = True
	columns[column][number] = True 
	board[row][column] = number
	locations.pop()

def take(board, square, number):
	row, column = square
	board[row][column] = 0
	rows[row][number] = False
	columns[column][number] = False 
	locations.append(square)

def solve(board):
	square =  nextLocation()
	if not square: return True
	row, column = square

	for number in xrange(1,10):

		if validMove(board, square, number):

			put(board, square, number)
			if solve(board):  return True
			take(board, square, number)

	return False

rows = [[False for i in xrange(11)] for j in xrange(10)]
columns = [[False for i in xrange(11)] for j in xrange(10)]

board = read()
locations = locationsInit(board)
solve(board)
write(board)
