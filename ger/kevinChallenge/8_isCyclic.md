This checks a graph to see if it has a cycle using df traversal.
It is part of my adjacency list graph class
```python
    def isCyclic(self):

        def isCyclicR(self, v, visited, stck):
            stck[v] = True
            visited[v] = True

            for to in self.adjacencyList[v]:
                if not visited[to]:
                    if isCyclicR(to, visited, answer): return True
                    elif stck[visited]: return True
                
            stck[v] = False
            return False

        stck = {i:False for i in self.adjacencyList}
        visited = {i:False for i in self.adjacencyList}

        for vertex in self.adjacencyList:
            if not visited[vertex]:
                if isCyclicR(vertex, visited, stck): return True
            return False
```