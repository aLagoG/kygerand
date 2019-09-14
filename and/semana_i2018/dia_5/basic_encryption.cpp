#include <stdio.h>

int n, s;
char c;

int main() {
    scanf("%d %d", &n, &s);
    scanf("%c", &c);
    s %= 26;
    while (scanf("%c", &c) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            printf("%c", (((c - 'A') - s + 26) % 26) + 'A');
        } else if (c >= 'a' && c <= 'z') {
            printf("%c", (((c - 'a') - s + 26) % 26) + 'a');
        } else {
            printf("%c", c);
        }
    }
}