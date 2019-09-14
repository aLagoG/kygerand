#include <stdio.h>

typedef unsigned long long ull;

int readIdx() {
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    return a * 1000 + (b - 1) * 50 + c - 1;
}

int main() {
    int n, q, min, max;
    scanf("%d %d", &n, &q);
    min = readIdx();
    max = readIdx();
    int len = max - min + 1;
    int a[len];
    for (int i = 0; i < len; ++i) {
        a[i] = 0;
    }
    int prev = 0, curr;
    ull val;
    while (n--) {
        scanf(" R ");
        curr = readIdx() - min;
        scanf("%llu", &val);
        for (int i = prev + 1; i < curr; ++i) {
            a[i] = a[prev];
        }
        a[curr] = a[prev] + val;
        prev = curr;
    }
    int s, e;
    while (q--) {
        scanf(" Q ");
        s = readIdx() - min;
        e = readIdx() - min;
        printf("%llu\n", a[e] - (s > 1 ? a[s - 1] : 0));
    }
}