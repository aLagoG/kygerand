The topological sort algorithm is the answer to a simple question:
A linear ordering of the vertices in a DAC such that such that for every edge uv u comes before v in the ordering.

Such ordering can be obtained by doing a depth first traversal of the graph and storing the traversed vertices.

Here's the implementation:


```python
    def topSort(self):

        def topSortR(v, visited, answ):
            visited[v] = True
            for vertex in self.adjacencyList[v]:
                if not visited[vertex]: topSortR(vertex, visited, answ)
            answ.append(v)

        visited = [False for i in self.adjacencyList]
        answer = []

        for v in self.adjacencyList:
            if not visited[v]: topSortR(v, visited, answer)

        return answer
```