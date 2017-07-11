#include <stdio.h>

typedef unsigned long long ull;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ull n;
        scanf("%llu\n", &n);
        printf("%llu\n", (n + 1) * (n + 1) - 1);
    }
}