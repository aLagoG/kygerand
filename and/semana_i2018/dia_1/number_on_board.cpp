#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

int counts[10];

int main() {
    int k, sum = 0, changes = 0;
    scanf("%d", &k);
    char tmp;
    while (scanf(" %c", &tmp) != EOF) {
        counts[tmp - '0']++;
        sum += tmp - '0';
    }
    if (sum < k) {
        int diff = k - sum;
        for (int i = 0; i < 9 && diff > 0; i++) {
            int ch = min((int)ceil(diff / (9.0 - i)), counts[i]);
            changes += ch;
            diff -= ch * (9 - i);
        }
    }
    printf("%d\n", changes);
}
