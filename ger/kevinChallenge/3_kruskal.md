Kruskal's algorithm is a greedy process that finds a minimum spanning tree in a weighted graph.

It tries to build the answer by iterating through the sorted edges and checking if the vertices they join have not been joined.

```python
def kruskal_mst(self):
        def getSet(v):
            for s in sets:
                if v in s: return s
            return None

        def sameset(v1, v2):
            for s in sets:
                if v1 and v2 in s: return True
            
            return False
        
        sets = [ set([vertex]) for vertex in  self.vertices  ]
        answer = [] 

        for edge in sorted(self.edges, key=lambda x : x[-1] ):
            v0, v1 = edge[0:2]
            if not sameset(v0, v1):
                answer.append(edge)
                getSet(v0).remove(v0)
                getSet(v1).add(v0)

                
        return answer
```