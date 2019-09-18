#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    unsigned int v, n;
    scanf("%d %d", &v, &n);
    for (double i = 10; i < 99; i += 10) {
        printf("%d", (int)ceil(v * i * n / 100.0));
        if (i < 89) {
            printf(" ");
        }
    }
    printf("\n");
}
