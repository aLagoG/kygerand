#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    int n;
    scanf("%d", &N);
    for (int iii = 1; iii < N + 1; iii++) {
        unsigned long long count = 0;
        scanf("%d", &n);
        for (unsigned long long i = 1; i * (i + 1) < 2 * n; i++) {
            unsigned long long d = n - (i * (i + 1) / 2);
            if (d % (i + 1) == 0)
                count++;
        }
        printf("case %d: %lld\n", iii, count);
    }
    return 0;
}
