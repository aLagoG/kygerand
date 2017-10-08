
class edgeListGraph:
    def __init__(self):
        self.edges = []
        self.vertices = set()

    def addEdge(self, a, b, w):
        self.edges.append([a, b, w])
        self.vertices.add(a)
        self.vertices.add(b)

    
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

fuchiGraph = edgeListGraph()
fuchiGraph.addEdge(0, 1, 3)
fuchiGraph.addEdge(1, 2, 5)
fuchiGraph.addEdge(2, 3, 2)
fuchiGraph.addEdge(1, 4, 4)
fuchiGraph.addEdge(2, 4, 6)
fuchiGraph.addEdge(3, 4, 7)
fuchiGraph.addEdge(0, 4, 1)

print(fuchiGraph.kruskal_mst())