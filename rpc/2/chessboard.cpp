#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    char t;
    while (scanf("%d %c", &n, &t) != EOF) {
        if (t == 'R' || t == 'B') {
            printf("%d\n", n);
        } else if (t == 'K') {
            printf("%d\n", min(n, 2));
        } else if (t == 'N') {
            if (n < 3) {
                printf("1\n");
            } else {
                printf("%d\n", min(n, 2));
            }
        }
    }
}
