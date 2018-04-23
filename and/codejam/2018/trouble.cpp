#include <stdio.h>
#include <algorithm>

#define N 50005
#define M_INF -1000000001

using namespace std;

int evens[N];
int odds[N];

int main() {
    int  t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int ne = 0, no = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            if (j & 1) {
                scanf("%d", &odds[no++]);
            } else {
                scanf("%d", &evens[ne++]);
            }
        }
        sort(evens, evens + ne);
        sort(odds, odds + no);
        int je = 0, jo = 0, last = M_INF;
        bool failed = 0;
        int fail_idx = -1;
        for (int j = 0; j < n && !failed; j++) {
            if (j & 1) {
                if (odds[jo] < last) {
                    failed = 1;
                    fail_idx = j - 1;
                } else {
                    last = odds[jo];
                }
                jo++;
            } else {
                if (evens[je] < last) {
                    failed = 1;
                    fail_idx = j - 1;
                } else {
                    last = evens[je];
                }
                je++;
            }
        }
        printf("Case #%d: ", i + 1);
        if (failed) {
            printf("%d\n", fail_idx);
        } else {
            printf("OK\n");
        }
    }
}