# #include <iostream>
# #include <vector>

# #define N 101

# using namespace std;

# int n, m;
# vector<int> g[N];
# bool vst[N];

# bool dfs(int node){
#     if(vst[node]){
#         return false;
#     }
# }

# int main(){
#     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#     cin >> n >> m;
#     int a,b;
#     for(int i=0;i<m;i++){
#         cin >> a >> b;
#         g[a].push_back(b);
#         g[b].push_back(a);
#     }
#     cout << dfs(0);
# }


class Graph:
    def __init__(self):
        self.edges = []
        self.vertices = set()

    def addEdge(self, a, b):
        self.edges.append([a, b])
        self.vertices.add(a)
        self.vertices.add(b)

    def kruskal_mst(self):
        def getSet(v):
            for s in sets:
                if v in s: return s
            return None

        def sameset(v1, v2):
            for s in sets:
                if v1 in s and v2 in s: return True

            return False

        sets = [set([vertex]) for vertex in self.vertices]
        edges = 0
        nodes = set()

        for edge in self.edges:
            v0, v1 = edge
            if not sameset(v0, v1):
                edges += 1
                nodes.add(v0)
                nodes.add(v1)
                v0_s = getSet(v0)
                v1_s = getSet(v1)
                v1_s |= v0_s
                sets.remove(v0_s)

        return edges, len(nodes)


n, m = [int(x) for x in input().split()]
g = Graph()
for i in range(m):
    g.addEdge(*[int(x) for x in input().split()])
edges,nodes = g.kruskal_mst()
print("FHTAGN!" if edges + 1 == m and nodes == n else "NO")