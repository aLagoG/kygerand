#include <stdio.h>

int main() {
    int t, n, k, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        int res = k;
        int kth;
        for (int i = 1; i <= k; i++) {
            scanf("%d", &s);
            if (i == k) {
                kth = s;
            }
            if (!s) {
                res--;
            }
        }
        for (int i = k; i < n; i++) {
            scanf("%d", &s);
            if (s == kth && s) {
                res++;
            }
        }
        printf("%d\n", res);
    }
}