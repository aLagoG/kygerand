Depth and Breadth - first traversals in graphs

Graphs can be represented in several different ways inside a computer.
Different ways are better in different aspects such as memory space and lookup (search) times with V vertices and E edges.

For this exercise I considered the following three representations:
* As an edge list.
* As an adjacency matrix.
* As a list of adjacency lists.

The list of adjacency lists is a nice in-between the first two so I'll use that.
I will also use python 3 for the implementation, because [the example](http://www.geeksforgeeks.org/breadth-first-traversal-for-a-graph/) made me realize python has ["high performance collections"](https://docs.python.org/3.6/library/collections.html).

While "visiting" any node, the breath first algorithm "visits" every "adjacent" node of that node before moving on to visit the adjacencies of them and so on. To achieve that, the nodes are queued before being processed.
It's counter part "visits" the first adjacent node for any given node, and proceeds to do the same in the next adjacency when there are no more nodes to visit in the traversal of the first adjacency.


Here is it:
```python
from collections import defaultdict
from collections import deque

class AdjListGraph:
    def __init__(self, itrble=None):
        self.adjacencyList = defaultdict(lambda: None)
        self.E = 0
        if itrble:
            for frm, to in itrble:
                self.adjacencyList[frm].append(to)


    def addEdge(self, a, b):
        self.adjacencyList[a].append(b)
        self.E += 1
    
    #bft implementation
    def bft(self, start):
        visited = defaultdict(bool)
        queue = deque()
        
        answer = []

        queue.append(start)
        visited[start] = True

        while queue:
            v = queue.popleft()
            answer.append(v)
            
            for to in self.adjacencyList[v]:
                if not visited[to]:
                    queue.append(to)
                    visited[to] = True
                
        return answer
            

    #dft implementation
    def dftR(self, v, visited, answer):
        answer.append(v)
        visited[v] = True

        for to in self.adjacencyList[v]:
            if not visited[to]:
                self.dftR(to, visited, answer)
        
    def dft(self, start):
        visited = defaultdict(bool)
        answer = []
        self.dftR(start, visited, answer)
        return answer
```