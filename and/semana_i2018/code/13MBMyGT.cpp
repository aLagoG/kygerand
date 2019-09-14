#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define FORC(cont, it) \
    for (decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

// Maximum Bipartite Matching
// Dados 2 subsets y sus conexiones cual es la mayor cantidad de parejas que se
// pueden formar? Variacion: solo hay 1 subset y las parejas se tienen que
// formar dentro de el.

// Problema diferente a MBM
// Cada edge tiene un costo: Algoritmo Hungaro
// Es un MBM pero con costo cada edge

#define maxN 1000

int N, L[maxN], R[maxN], u[maxN], v[maxN], pre[maxN];
vi edges[maxN];

// O(V*E)
// Easy to code
bool dfs(int n) {
    if (v[n]) return false;
    v[n] = true;
    FOR(i, 0, edges[n].size()) {
        int e = edges[n][i];
        if (R[e] == -1 || dfs(R[e])) {
            L[n] = e;
            R[e] = n;
            return true;
        }
    }
    return false;
}

// sqrt(V)*E
// Harder to code, but easy to transform from MBM BFS, and it's faster
// 99% of the time, this won't be needed and DFS is more than enough, use this
// if constraints are super tight
int bfs() {
    int ret = 0;
    queue<int> q;
    memset(v, 0, sizeof(v));
    FOR(i, 0, N) {
        u[i] = 0;
        pre[i] = -2;
        if (L[i] == -1) {
            q.push(i);
            pre[i] = -1;
        }
    }
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        FOR(i, 0, edges[f].size()) {
            int next = edges[f][i];
            if (R[next] == -1) {
                int tf = f, tnext = next, m = 0;
                while (tf >= 0 && !m) {
                    m |= u[tf] | v[tnext];
                    u[tf] = v[tnext] = 1;
                    tnext = L[tf];
                    tf = pre[tf];
                }
                if (m) continue;
                while (f >= 0) {
                    R[next] = f;
                    tnext = next;
                    next = L[f];
                    L[f] = tnext;
                    f = pre[f];
                }
                ret++;
            } else {
                int ol = R[next];
                if (pre[ol] == -2) {
                    q.push(ol);
                    pre[ol] = f;
                }
            }
        }
    }
    return ret;
}

int main() {
    // Just to see max amount of times bfs MBM was called
    int hi = 0;
    FOR(i, 0, 1000) {
        N = rand() % 100 + 1;
        int M = rand() % 100 + 1;
        FOR(j, 0, N) {
            edges[j].clear();
            int k = rand() % 20;
            FOR(kk, 0, k) {
                edges[j].push_back(rand() % M);
            }
        }
        // MBM DFS
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        int ans1 = 0;
        FOR(j, 0, N) {
            memset(v, false, sizeof(v));
            if (dfs(j)) ans1++;
        }

        // MBM BFS
        int t, ans2 = 0;
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        // thi corresponds to the amount of times we need to iterate through the
        // entire graph, which is going to be smaller than 2*sqrt(N)
        int thi = 0;
        while ((t = bfs())) {
            ans2 += t;
            thi++;
        }
        hi = max(hi, thi);
        // In theory this line should never be true
        if (ans1 != ans2) {
            cerr << "Error" << endl;
            cout << "Error" << endl;
        }
    }
    cout << hi << endl;

    // Game theory:

    // Hay 2 maneras de pensarlos
    // 1) Standard Recursive
    // Al menos 1 lose-> win (es decir si te puedes mover a una posicion
    // perdedora estas en una ganadora, puesto que te moveras a la perdedora y
    // sera el turno de tu oponente) 0 lose y al menos 1 draw -> draw (si no te
    // puedes mover a una posicion perdedora pero si a una de empate te mueves
    // ahi, para empatar) 0 lose y 0 draw -> lose (si solo te puedes mover a
    // posiciones ganadoras es una posicion perdedora ya que el oponente quedara
    // en posicion ganadora)

    // 2) BFS (Eratosthenes logic)
    // lose -> win (if not in Q, push to Q)
    // if all states x can visit are true, then x is lose (push x to Q)
    // Once Q is empty, all states that are neither win or lose are draw

    // Grundy numbers:
    // El valor de cada posicion es el primer valor al cual no podemos llegar
    // desde dicho estado (notar que cada valor son numeros enteros >=0) 0
    // indica un estado que pierde, cualquier otro es un estado ganador. Por
    // ejemplo si tenemos una pila con 10 piedras y se tienen que quitar entre 1
    // y 4 piedras, y el que quite la ultima piedra gana: Piedras Valor 0
    // 0 1	   1 2	   2 3	   3 4	   4 5	   0 (notar que lleva a estados
    // 1, 2, 3 y 4, pero no existe valor 0, por ende vale 0) 6	   1 7	   2 8
    // 3 9	   4 10	   0 (notar que hay un patron)

    // Cuando tenemos muchos subjuegos, cada uno con su propio grundy number,
    // podemos hacer xor entre todos ellos y eso establece el nuevo grundy
    // number. Por ejemplo si tenemos 2 pilas de piedritas, una con 2 y la otra
    // con 3 el grundy number se vuelve 1 (2^3==1)
    return 0;
}
