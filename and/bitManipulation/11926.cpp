#include <stdio.h>
#include <bitset>

using namespace std;
bitset<1000000> set;

inline bool addOne(int s, int e) {
    e = e >= 1000000 ? 1000000 : e;
    for (int i = s; i < e; i++) {
        if (set[i]) {
            return true;
        }
        set.set(i);
    }
    return false;
}

inline bool addSome(int s, int e, int r) {
    int c = s;
    int ran = e - s;
    while (c < 1000000) {
        if (addOne(c, c + ran)) {
            return true;
        }
        c += r;
    }
    return false;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n || m) {
        set.reset();
        int s, e, r;
        bool hasConflict = false;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &s, &e);
            if (!hasConflict && addOne(s, e)) {
                hasConflict = true;
            }
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &s, &e, &r);
            if (!hasConflict && addSome(s, e, r)) {
                hasConflict = true;
            }
        }
        printf(hasConflict ? "CONFLICT\n" : "NO CONFLICT\n");
    }
}