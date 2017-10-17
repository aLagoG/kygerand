This algorithm is the actual proof that the 3-SAT problem is NP-complete, it converts the boolean circuit of a K-SAT problem into the input of a 3-SAT problem. It reads .cnf files.

```python
def makeVariables(n):
    toRet = []
    global top
    for i in range(n):
        toRet.append(top + 1)
        top += 1

    return toRet

def forOne(clause):
    v1, v2 = makeVariables(2)
    z1 = clause[0]
    return [
        [v1, v2, z1],
        [v1, -1*v2, z1],
        [-1*v1, v2, z1],
        [-1*v1, -1*v2, z1]
    ]

def forTwo(clause):
    v1 = makeVariables(1)[0]
    z1, z2 = clause
    return [
        [v1, z1, z2],
        [-1*v1, z1, z2]
    ]

def forMore(clause, n):
    toRet = []
    newVars = makeVariables(n-3)

    toRet.append([clause[0], clause[1], -1*newVars[0]])

    for i in range(1, n-3):
        toRet.append( [ newVars[i-1], clause[i+1], -1*newVars[i] ] )

    toRet.append([newVars[-1], clause[-2], clause[-1]])
    
    return toRet



clauses = []
answer = []
top = 1

with open(input()) as f:
    for line in f:
        line = line.strip()
        if line[0] == "c": continue
        elif line[0] == "p":
            top = int(line.split(" ")[2])
        else:
            clauses.append(line.split(" ")[:-1])


for clause, k in zip(clauses, [len(i) for i in clauses]):
    if k == 1: 
        for el in forOne(clause): answer.append(el)
    elif k == 2:
        for el in forTwo(clause): answer.append(el)
    elif k == 3:
        answer.append(clause)
    elif k > 3:
        for el in forMore(clause, k): answer.append(el)
    else:
        raise Exception("Invalid clause!")

for el in answer:
    print(el)

```