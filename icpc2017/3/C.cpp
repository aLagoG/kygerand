#include <math.h>
#include <stdio.h>

char solution[32];

int main() {
    int n, g;
    while (scanf("%d %d", &n, &g) != EOF) {
        int index = 0;
        int d = (1 << n) - 1;
        int f = floor(log2(d - g + 1));
        int ini = d - (1 << f) + 1;
        int off = ini - g + 1;
        while (f) {
            if (off > (1 << (f - 1))) {
                solution[index++] = 'R';
                off -= 1 << (f - 1);
            } else {
                solution[index++] = 'L';
            }
            f--;
        }
        solution[index] = '\0';
        printf("Instructions: %s\n", solution);
    }
}