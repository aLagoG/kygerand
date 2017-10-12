from bheap import bheap

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
