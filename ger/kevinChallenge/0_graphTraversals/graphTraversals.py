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
        
