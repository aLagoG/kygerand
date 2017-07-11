#define _CRT_SECURE_NO_DEPRECATE
#define ALL(x) x.begin(), x.end()

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    char alf[10];
    for (int i = 0; i < 10; i++) alf[i] = 'A' + i;
    do {
        for (int f = 0; f < 10; f++) printf("%c ", alf[f]);
        printf("\n");
    } while (next_permutation(alf, alf + 10));
}