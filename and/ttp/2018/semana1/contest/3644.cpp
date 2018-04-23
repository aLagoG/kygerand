#include <stdio.h>
#include <cmath>

int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        long long cnt = 0;
        while (n) {
            long long f = floor((sqrt(1.0 + 8 * n) - 1) / 2.0);
            n -= (f * (f + 1)) / 2;
            cnt++;
        }
        printf("%lld\n", cnt);
    }
}