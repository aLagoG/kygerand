#include <stdio.h>

int main() {
    char tmp;
    int cnt = 0;
    while (scanf("%c", &tmp) != EOF) {
        if (tmp == '1') {
            ++cnt;
        }
    }
    printf("%d\n", (cnt * (cnt + 1)) / 2);
}
