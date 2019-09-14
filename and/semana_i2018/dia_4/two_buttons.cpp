#include <iostream>
#include <queue>

using namespace std;

const int maxn = int(1e4 + 1);

int a, b;
bool vst[maxn];

typedef pair<int, int> pii;

int main() {
    cin >> a >> b;
    queue<pii> q;
    q.push(pii(a,0));
    pii current;
    while (q.size()) {
        current = q.front();
        q.pop();
        if(current.first == b){
            break;
        }
        if (current.first - 1 >= 0 && !vst[current.first - 1]) {
            q.push(pii(current.first - 1, current.second + 1));
            vst[current.first - 1] = 1;
        }
        if (current.first << 1 < maxn && !vst[current.first << 1]) {
            q.push(pii(current.first << 1, current.second + 1));
            vst[current.first << 1] = 1;
        }
    }
    cout << current.second << '\n';
}
