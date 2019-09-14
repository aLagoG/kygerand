#include <cstdio>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> i3;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

int main() {
    int V, E, s, d, l, c;

    scanf("%d %d", &V, &E);
    // v -> l, c
    vector<unordered_map<int, ii>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d %d", &s, &d, &l, &c);
        ii tmp = ii(l, c);
        if (!(graph[s][d].first && graph[s][d].second) || graph[s][d] > tmp) {
            graph[s][d] = tmp;
        }
        if (!(graph[d][s].first && graph[d][s].second) || graph[d][s] > tmp) {
            graph[d][s] = tmp;
        }
    }

    vi dist(V + 1, INF);
    vi cost(V + 1, 0);
    dist[1] = 0;
    priority_queue<i3, vector<i3>, greater<i3>> pq;
    // l, c, v
    pq.push(i3(0, ii(0, 1)));
    while (!pq.empty()) {
        i3 front = pq.top();
        pq.pop();
        l = front.first;
        c = front.second.first;
        int u = front.second.second;
        if (l > dist[u]) {
            continue;
        }
        for (auto k : graph[u]) {
            int v = k.first;
            l = k.second.first;
            c = k.second.second;
            if (dist[u] + l < dist[v] ||
                (dist[u] + l == dist[v] && c < cost[v])) {
                dist[v] = dist[u] + l;
                cost[v] = c;
                pq.push(i3(dist[v], ii(cost[v], v)));
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= V; i++) {
        res += cost[i];
    }
    printf("%d\n", res);
}