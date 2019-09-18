#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

#pragma region wgraph

struct Edge {
    int a = 0, b = 0, weight = 0;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    };
    Edge() {}
    Edge(int _a, int _b, int _weight) {
        a = _a;
        b = _b;
        weight = _weight;
    };
};

struct Graph {
    int V, E;
    vector<Edge> edges;
    Graph(int v, int e) {
        V = v;
        E = e;
        edges = vector<Edge>(E);
    }
};

#pragma endregion wgraph

#pragma region unionfind

struct Subset {
    int parent, rank;
};

int find(vector<Subset>& subsets, int i) {
    // if i is not parent, compress path to the
    // actual parent by pointing straight to it
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void _union(vector<Subset>& subsets, int x, int y) {
    int root_x = find(subsets, x), root_y = find(subsets, y);

    // smaller 'tree' becomes child
    // of biger 'tree'
    if (subsets[root_x].rank > subsets[root_y].rank) {
        subsets[root_y].parent = root_x;
    } else if (subsets[root_x].rank < subsets[root_y].rank) {
        subsets[root_x].parent = root_y;
    } else {
        subsets[root_y].parent = root_x;
        subsets[root_x].rank++;
    }
}

#pragma endregion unionfind

int t, n, c, p;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> c;

        vector<Subset> subsets(n);
        for (int i = 0; i < n; i++) {
            subsets[i].parent = i;
            subsets[i].rank = 0;
        }

        int a, b, w;
        int seta, setb;
        for (int i = 0; i < c; ++i) {
            cin >> a >> b >> w;
            --a;
            --b;
            seta = find(subsets, a);
            setb = find(subsets, b);
            _union(subsets, seta, setb);
        }
        // for (auto& subs : subsets) {
        //     cout << subs.parent << endl;
        // }

        cin >> p;
        Graph g(n, p);
        for (int i = 0; i < p; ++i) {
            cin >> g.edges[i].a >> g.edges[i].b >> g.edges[i].weight;
            --g.edges[i].a;
            --g.edges[i].b;
        }

        unsigned long long cost = 0;

        sort(g.edges.begin(), g.edges.end());

        for (auto& edge : g.edges) {
            seta = find(subsets, edge.a);
            setb = find(subsets, edge.b);

            if (seta != setb) {  // sides of cur are not together
                _union(subsets, seta, setb);
                cost += edge.weight;
            }
        }

        bool solved = true;
        int par = subsets[0].parent;
        // cout << endl;
        for (auto& subs : subsets) {
            // cout << subs.parent << endl;
            if (subs.parent != par) {
                solved = false;
                break;
            }
        }

        if (!solved) {
            cout << "You better hire someone else\n";
            continue;
        }
        if (!cost) {
            cout << "Thank you, Goodbye\n";
        } else {
            cout << cost << '\n';
        }
    }
}
