#include <stdio.h>

int main() {
    int s, v1, v2, t1, t2;
    scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);
    int a = (2 * t1) + (s * v1);
    int b = (2 * t2) + (s * v2);
    if (a < b) {
        printf("First\n");
    } else if (b < a) {
        printf("Second\n");
    } else {
        printf("Friendship\n");
    }
}
