class Node:
    def __init__(self, value,  parent = None):
        self.parent = parent
        self.value = value
        self.children = [None, None]
    
    def __str__(self):
        return str(self.value)

class BinaryTree:
    def __init__(self, value = None):
        self.root = Node(value)
    
    def add(self, value):
        if self.root is None:
            self.root = Node(value)
            return
        self.insert(self.root, value)

    def insert(self, node, value):
        if value >= node.value:
            if node.rightChild is None:
                node.rightChild = Node(value)
                return
            self.insert(node.rightChild, value)
        else:
            if node.leftChild is None:
                node.leftChild = Node(value)
                return
            self.insert(node.leftChild, value)

    def bf(self, node):
        if node == self.root: print(node.value)
        print(node.children)
        for child in node.children:
            if child is not None: 
                print(child.value)
        
        for child in node.children:
            if child is not None: bf(child)


tree = BinaryTree(100)
tree.add(90)
tree.add(110)
print(tree.root.children)

tree.bf(tree.root)
