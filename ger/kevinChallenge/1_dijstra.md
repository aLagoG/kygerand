Dijkstra's algorithm (part 1)

We've all heard of it. For finding shortest paths in graphs.
I gave it a try using the class form yesterday, but it turns out it isn't really cool unless you use a fibonacci heap as a heap for it.

So todays implementation is slow, but tomorrow I will do fib heap and implement it with that. yahooo!

Today's
```python
    def dijkstra(self, start, target):
        def decKey(heap, weights, v, newWeight):
            heap[ bisect.bisect_left(heap, (weights[v], v) ) ] = (newWeight, v)
            weights[v] = weight
            heapq.heapify(heap)

        path = []

        weights = {math.inf for i in self.adjacencyList}
        heap = heapq.heapify([(weights[vertex], vertex) for vertex in self.adjacencyList])
        inheap = {vertex:True for vertex in self.adjacencyList}
        
        decKey(heap, weights, start, 0)

        while len(heap) < 0:
            wu, u = heapq.heappop()
            inheap[u] = False
            path.append(u)
            if u == target: break

            for v in self.adjacencyList[u]:
                if inheap[v] and wu + 1 < weights[v]:
                    decKey(heap, weights, u, weights[v]+1)
        return path
```