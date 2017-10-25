from collections import defaultdict
import math

class bheap:
    def __init__(self, key=lambda x:x):
        self.heap = []
        self.max_i = -1
        self.comp = key

    def parent(self, i): return (i-1) // 2
    def left_child(self, i): return (2*i) + 1
    def right_child(self, i): return (2*i) + 2

    def hswap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def sift_up(self, cur_idx):
        if cur_idx < 1: return
        parent_idx = self.parent(cur_idx)
        if self.comp(self.heap[cur_idx]) < self.comp(self.heap[parent_idx]):
            self.hswap(cur_idx, parent_idx) 
            self.sift_up(parent_idx)
        else: return

    def sift_down(self, cur_idx):

        lef_child_idx = self.left_child(cur_idx)
        right_child_idx = self.right_child(cur_idx)
        
        if lef_child_idx > self.max_i and right_child_idx > self.max_i: return

        if lef_child_idx > self.max_i and right_child_idx <= self.max_i:
            min_child_idx = right_child_idx
        elif lef_child_idx <= self.max_i and right_child_idx > self.max_i:
            min_child_idx = lef_child_idx
        else:
            left_child = self.heap[lef_child_idx]
            right_child = self.heap[right_child_idx]
            
            min_child_idx = lef_child_idx if self.comp(left_child) <= self.comp(right_child) else right_child_idx
        
        self.hswap(cur_idx, min_child_idx)
        self.sift_down(min_child_idx)
    
    def insert(self, n):
        self.heap.append(n)
        self.max_i += 1
        self.sift_up(self.max_i)
    
    def extract_min(self):
        toRet = self.heap[0]
        self.heap[0] = self.heap.pop()
        self.max_i -= 1
        self.sift_down(0)
        return toRet
    
    def update_key(self, i, value):
        old_value = self.heap[i]
        self.heap[i] = value
        
        if value < old_value: self.sift_up(i)
        elif value > old_value: self.sift_down(i)

    def peek(self):
        return self.heap[0]

    def __len__(self): return len(self.heap)

class pqueue(bheap):
    def __init__(self, key=lambda x: x):
        super(pqueue, self).__init__(key)
        self.keys = {}
    
    def hswap(self, i, j):
        self.keys[self.heap[i]], self.keys[self.heap[j]] = self.keys[self.heap[j]], self.keys[self.heap[i]]
        super(pqueue, self).hswap(i, j)

    def insert(self, n):
        self.heap.append(n)
        self.max_i += 1
        self.keys[n] = self.max_i
        self.sift_up(self.max_i)

    def extract_min(self):
        del self.keys[self.heap[0]]
        return super(pqueue, self).extract_min()

    def update_key(self, key, value):
        old_value = self.heap[self.keys[key]]
        self.heap[self.keys[key]] = value
        
        if value < old_value: self.sift_up(self.keys[key])
        elif value > old_value: self.sift_down(self.keys[key])

    def get(self, key):
        return self.heap[self.keys[key]]


class AdjListGraph:
    def __init__(self):
        self.adjacencyList = defaultdict(lambda: [])
        self.E = 0

    def addEdge(self, a, b, w):
        self.adjacencyList[a].append((b, w))
        self.E += 1        

    def dijkstra(self, start, target): # O(nlog(n))
        V = len(self.adjacencyList)
        path = set()
        cost_sum = 0
        queue = pqueue(key=lambda x: x[1])
        print(queue)
        for v in self.adjacencyList:
            queue.insert( (v, math.inf if v != start else 0))

        while len(queue):
            u, cost_here = queue.extract_min()

            if u == target: break
 
            for v in self.adjacencyList[u]:
                if v not in path and cost_here < queue.get(v[0])[1]:
                    queue.update_key(cost_here + v[1])

        return (path, cost_here)



while True:
    intersections = int(input())
    if intersections == 0: break

    graph = AdjListGraph()
    
    for i in range(intersections):
        streets = input().split('   ')[1:]

        for street in streets:
            street = street.split()
            graph.addEdge(i, street[0], street[1])

    start, target = [int(i) for i in input().split()]
    # print(graph.adjacencyList)
    print(graph.dijkstra(start, target))
    
    
    input()
    input()
