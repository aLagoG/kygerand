def die(i, j):
    ones = 0
    #up
    if i > 0:
        if matrix[i-1][j] == 1:
            ones += 1
    #down
    if i < maxi-1:
        if matrix[i+1][j] == 1:
            ones += 1
    #left
    if j > 0:
        if matrix[i][j-1]:
            ones += 1
    #right
    if j < maxj-1:
        if matrix[i][j+1]:
            ones += 1
    
    return ones >= 2

inmatrix = [] 
while 1:
    try:
        inmatrix.append(input())
    except:
        break

matrix = []
for i in inmatrix:
    i = i.rstrip("\r")
    matrix.append([int(j) for j in i])

maxi = len(matrix)
maxj = len(matrix[0])


while 1:
    changed = False

    for i in range(maxi):
        for j in range(maxj):
            if matrix[i][j] == 0 and die(i, j):
                matrix[i][j] = 1
                changed = True

    if not changed : break


for i in matrix:
    print( "".join([str(j) for j in i]))