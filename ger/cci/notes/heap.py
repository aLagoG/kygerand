class MinHeap: #0 based
    def __init__(self):#, itr = None):
        # if itr != none:
        self.heap = []
    
    def parent(self, i):
        return self.arr[(i-1)/2]
    
    def left(self, i): return 2*i + 1
    
    def right(self, i): return self.lef(i) + 1


