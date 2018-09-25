#include <stdio.h>

int n;
bool odd[101];

int main() {
    scanf("%d", &n);
    if (!(n & 1)) {
        printf("NO\n");
        return 0;
    }
    for (int i = 0, tmp; i < n; i++) {
        scanf("%d", &tmp);
        odd[i] = tmp & 1;
    }
    printf(odd[0] & odd[n - 1] ? "YES\n" : "NO\n");
}