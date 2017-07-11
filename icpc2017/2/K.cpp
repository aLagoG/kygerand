#include <stdio.h>
#include <cmath>
#include <set>

using namespace std;

int fml[1000001];

int main() {
    int n, w, k;
    set<int> s;
    while (scanf("%d %d %d", &n, &w, &k), n || w || k) {
        int i, j = 0;
        for (i = 0; i < w; i++) {
            scanf("%d", &fml[i]);
            // printf("%d %d\n", fml[i], i);
            s.insert(fml[i]);
        }
        int t;
        bool flag = true;
        for (; i < n; i++) {
            scanf("%d", &fml[i]);
            // printf("%d %d------\n", fml[i], i);
            if (abs(fml[i] - *s.begin()) > k || abs(fml[i] - *s.rend()) > k) {
                printf("No.\n");
                flag = false;
                break;
            }
            s.erase(s.begin());
            s.insert(fml[i]);
        }
        for (i++; i < n; i++) {
            scanf("%d", &fml[i]);
            // printf("%d %d------\n", fml[i], i);
        }
        if (flag) printf("Yes.\n");
        s.clear();
    }
}