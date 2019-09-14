#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef unsigned int uint;

inline int log2(int n) {
    int res = 0;
    while (n >>= 1) {
        ++res;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, tmp;
    cin >> n;
    map<uint, uint> m;
    uint mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp > mx) {
            mx = tmp;
        }
        m[tmp]++;
    }
    int res = n;
    for (auto& pr : m) {
        if (!pr.second) {
            continue;
        }
        uint p = max(1, log2(pr.first));
        uint gl = 1 << p;
        if (gl <= pr.first) {
            gl <<= 1;
        }
        for (; gl; gl <<= 1) {
            if (gl - pr.first > mx) {
                break;
            }
            auto ot = m.find(gl - pr.first);
            if (ot != m.end() && ((*ot).first != pr.first || pr.second > 1)) {
                res -= pr.second;
                break;
            }
        }
    }
    cout << res << endl;
}
