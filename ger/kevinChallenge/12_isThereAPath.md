Here we do a bfs to look for a path between two nodes. We return if such a path exists.
```python
    def has_path(self, start, targer):
        visited = {node:False for node in self.adjacencyList}
        queue = deque()
        queue.append(start)
        visited[start] = True 

        while queue:
            n = queue.popleft()

            if n == d: return True

            for adj in self.adjacencyList[n]:
                if visited[adj] == False:
                    queue.append(adj)
                    visited[edj] = True
            
        return False

```