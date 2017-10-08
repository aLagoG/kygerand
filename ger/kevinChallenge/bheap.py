#my own min binary heap with blackjack and h**kers
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
        self.heap[0] = self.heap.pop()
        self.max_i -= 1
        toRet = self.heap[0]
        self.sift_down(0)
        return toRet
    
    def update_key(self, i, value):
        old_value = self.heap[i]
        self.heap[i] = value
        
        if value < old_value: self.sift_up(i)
        elif value > old_value: self.sift_down(i)

    def peek(self):
        return self.heap[0]
        

# heap = bheap(key=lambda x: x[1])
# for k in range(10): heap.insert([0, k])
# heap.insert([0, -1])
# print(heap.heap)
# heap.extract_min()
# print(heap.heap)