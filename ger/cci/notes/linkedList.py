class Node:
    def __init__(self):
        self.data = None
        self.nxt = None

    def __init__(self, data):
        self.data = data
        self.nxt = None
    
    def __str__(self):
        return str(self.data)
    
    __repr__ = __str__

class LinkedList:
    def __init__(self, itrbl = None):
        self.first = None
        self.last = None
        if itrbl is not None:
            for el in itrbl:
                self.add(el)
    
    def add(self, val): #constant
        if self.first == None:
            self.first = Node(val)
            self.last = self.first
        else:
           self.last.nxt = Node(val)
           self.last =  self.last.nxt

    def get(self, idx): #linear
        cur = self.first
        for i in range(idx):
            if cur == None: return None
            else: cur = cur.nxt
        return cur.data

    def getNode(self, idx): #linear
        cur = self.first
        for i in range(idx):
            if cur == None: return None
            else: cur = cur.nxt
        return cur
            
    def index(self, data): #linear
        cur = self.first
        idx = 0
        while True:
            if cur == None: return None
            if cur.data == data: return idx
            cur = cur.nxt
            idx += 1

    def __str__(self):
        toRet = []
        cur = self.first
        if cur == None: return ""
        while True:
            if cur == None: break
            toRet.append(str(cur))
            cur = cur.nxt
        return "->".join(toRet)

    __repr__ = __str__

l = LinkedList(range(10))
print(l)

# l.last.nxt = l.getNode(5)

# for i in range(20):
#     print(l.getNode(i))