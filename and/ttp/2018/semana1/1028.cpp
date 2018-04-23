#include <stdio.h>
#include <string.h>

char a[35];
char b[35];

int main() {
    while (scanf("%s %s", a, b) != EOF) {
        int la = strlen(a), lb = strlen(b);
        if (la > lb) {
            printf("No\n");
            continue;
        }
        int i = 0;
        for (int j = 0; j < lb && i < la; j++) {
            if (a[i] == b[j]) {
                i++;
            }
        }
        if (i == la) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}