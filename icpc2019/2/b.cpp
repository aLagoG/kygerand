#include <stdio.h>

int main() {
    int best = -1;
    int best_i = -1;
    int n, t;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        if (t > best) {
            best_i = i;
            best = t;
        }
    }
    if (best_i == 0) {
        printf("S\n");
    } else {
        printf("N\n");
    }
}
