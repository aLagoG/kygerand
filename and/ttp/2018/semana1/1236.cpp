#include <stdio.h>

int main() {
    int a, b, c, d, e, f;
    int h[3];
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &h[0], &h[1], &h[2]);
    e = a + b;
    f = c + d;
    for (int i = 0; i < 3; i++) {
        bool x = h[i] % e > 0 && h[i] % e <= a;
        bool y = h[i] % f > 0 && h[i] % f <= c;
        if (x & y) {
            printf("both\n");
        } else if (x ^ y) {
            printf("one\n");
        } else {
            printf("none\n");
        }
    }
}