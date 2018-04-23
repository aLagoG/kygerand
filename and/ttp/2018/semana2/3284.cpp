#include <stdio.h>

int main() {
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    int pos = 1, dst = 0, tmp;
    m--;
    while (c--) {
        scanf("%d", &tmp);
        if (tmp >= pos && tmp <= pos + m) {
            continue;
        } else if (tmp < pos) {
            dst += pos - tmp;
            pos = tmp;
        } else if (tmp > pos + m) {
            dst += tmp - (pos + m);
            pos = tmp - m;
        }
    }
    printf("%d\n", dst);
}