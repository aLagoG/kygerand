#include <stdio.h>

int main() {
    int t, n, sum = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        if (n != 1) {
            sum++;
        }
    }
    printf("%d\n", sum);
}