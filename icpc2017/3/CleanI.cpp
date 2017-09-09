#include <stdio.h>
#include <vector>

using namespace std;

typedef  pair<int, int> pii;

struct Graph{
   int V, E;
   vector< pair<int, pii> > edges;

   Graph(int V, int E){
       this->V = V;
       this->E = E;
   }

   void addEdge(int u, int v, int w){
       edges.push_back({w, {u, v}});
   }

   int kruskal();
};

struct DisjointSets{
   int *parent, *rnk;
   int n;

   DisjointSets(int n){
       
       this->n = n;
       parent = new int[n+1];
       rnk = new int[n+1];

       for (int i = 0; i <= n; i++){
           rnk[i] = 0;

           parent[i] = i;
       }
   }

   int find(int u){
       if (u != parent[u])
           parent[u] = find(parent[u]);
       return parent[u];
   }

   void merge(int x, int y){
       x = find(x), y = find(y);
       if (rnk[x] > rnk[y])
           parent[y] = x;
       else
           parent[x] = y;

       if (rnk[x] == rnk[y])
           rnk[y]++;
   }
};

int Graph::kruskal(){
    int mst_wt = 200000;
    sort(edges.rbegin(), edges.rend());
    DisjointSets ds(V);
    vector< pair<int, pii> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++){
        // printf("%d %d %d\n", it->first,it->second.first, it->second.second);
        int u = it->second.first;
        int v = it->second.second;
 
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v){
            if(mst_wt > it->first){
                mst_wt = it->first;
            }
            ds.merge(set_u, set_v);
        }
    }
    return mst_wt;
 }

int main() {
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++){
        int n,m;
        scanf("%d %d", &n, &m);
        Graph g(n, m);
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            g.addEdge(a,b,c);
        }
        printf("Case #%d: %d\n", k,g.kruskal());
    }

}