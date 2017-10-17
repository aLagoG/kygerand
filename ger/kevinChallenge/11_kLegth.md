This will return true if the graph has a path of length target.

```python
    def path_len(self, start, goal):
        
        def path_len_r(node, length, goal, path):
            
            length += 1
            for v in self.adjacencyList[node]:

                if v in visited:
                    continue
                
                if length <= goal: return True

                visited[node] = True

                if path_len_r(v, length, goal, path):
                    return True
                
                path[v] = False
            
            length -= 1

             return False
```