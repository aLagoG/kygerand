from collections import defaultdict
from collections import deque
import math
import biscet
import pqueue #my own priotity queue using my heap

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
'''
    def dijkstra(self, start, target): # n^2 complexity 
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
'''
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
    def dft(self, start):

        def dftR(self, v, visited, answer):
            answer.append(v)
            visited[v] = True

            for to in self.adjacencyList[v]:
                if not visited[to]:
                    self.dftR(to, visited, answer)


        visited = defaultdict(bool)
        answer = []
        dftR(start, visited, answer)
        return answer
        
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