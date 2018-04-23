#include <stdio.h>

char c[4];
char a[] = {'B', 'U', 'G'};

int main() {
    int i = 0;
    while (scanf("%c", &c[i]) != EOF) {
        if (c[i] == a[i]) {
            i++;
        } else {
            if (c[i] == a[0]) {
                for (int j = 0; j < i; j++) {
                    printf("%c", c[j]);
                }
                c[0] = c[i];
                i = 1;
            } else {
                for (int j = 0; j <= i; j++) {
                    printf("%c", c[j]);
                }
                i = 0;
            }
        }
        if (i == 3) {
            i = 0;
        }
    }
}