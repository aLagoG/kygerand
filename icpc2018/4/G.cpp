#include <stdio.h>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        ull t, sq, sum = 0;
        bool found = false;
        scanf("%llu", &t);
        sq = sqrt(2 * t);
        for (int j = 1; j < sq && sum <= t; ++j) {
            sum += j;
            if ((t - sum) % (j + 1) == 0) {
                printf("case %d: %llu\n", i, (t - sum) / (j + 1));
                found = true;
                break;
            }
        }
        if(!found){
            printf("case %d: -1\n", i);
        }
    }
}