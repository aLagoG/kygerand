#!/usr/bin/env python
def rec(node, graph, visited):
    if len(graph[node]) == 0:
        return
    for child in graph[node]:
        if child not in visited:
            visited.add(child)
            rec(child, graph, visited)


done = False
while not done:
    try:
        mx = input()
    except:
        break
    nodes = {chr(x): [] for x in range(65, ord(mx) + 1)}
    while 1:
        try:
            r = input()
        except:
            done = True
            break
        if r == '':
            break
        nodes[r[0]].append(r[1])
        nodes[r[1]].append(r[0])
    cou = 0
    visited = set()
    for n in nodes:
        if n not in visited:
            rec(n, nodes, visited)
            cou += 1
    print(cou)
