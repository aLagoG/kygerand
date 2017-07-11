#include <stdio.h>
#include <string.h>

int weights[2 << 15];
int potencies[2 << 15];

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(potencies, 0, sizeof(potencies));
        int num = 1 << n;
        for (int i = 0; i < num; i++) {
            scanf(" %d ", &weights[i]);
            for (int j = 0; j < n; j++) {
                potencies[i ^ (1 << j)] += weights[i];
            }
        }
        int max = -1;
        for (int i = 0; i < num; i++) {
            for (int j = 0; j < n; j++) {
                if (potencies[i] + potencies[i ^ (1 << j)] > max) {
                    max = potencies[i] + potencies[i ^ (1 << j)];
                }
            }
        }
        printf("%d\n", max);
    }
}