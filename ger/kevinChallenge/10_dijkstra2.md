Finally! I implemented an efficient priority queue and used to optimize my Dijkstra algorithm. Here it is:

```python
def dijkstra(self, start, target): # O(nlog(n))
        V = len(self.adjacencyList)
        path = set()
        queue = pqueue(key=lambda x: x[1])
        for v in self.adjacencyList: queue.insert((v, math.inf if v != start else 0))

        while len(path) != V:
            u, cost_here = queue.extract_minn()
            path.add(u)
            if u == target: break
            for v in self.adjacencyList[u]:
                if v not in path and cost_here < queue.get(v)[1]:
                    queue.update_key(cost_here + 1)

        return path
```