#include <stdio.h>

int lst[200001];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &lst[i]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            while (lst[i] != i + 1) {
                int idx = lst[i] - 1;
                int tmp = lst[i];
                lst[i] = lst[idx];
                lst[idx] = tmp;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}