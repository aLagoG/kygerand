#include <stdio.h>
#include <cmath>

typedef unsigned long long ull;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ull n, s;
        bool done = false;
        scanf("%llu", &n);
        n <<= 3;
        n++;
        s = sqrt(n);
        if (s * s == n) {
            s--;
            n = s >> 1;
            if (n << 1 == s) {
                printf("%llu\n", n);
                done = true;
            }
        }
        if (!done) {
            printf("-1\n");
        }
    }
}