#include <stdio.h>

typedef unsigned long long ull;

int rec(ull n) {
    if (n < 10) {
        return n;
    }
    ull sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return rec(sum);
}

int main() {
    ull n;
    while (scanf(" %llu ", &n), n) {
        printf("%d\n", rec(n));
    }
}