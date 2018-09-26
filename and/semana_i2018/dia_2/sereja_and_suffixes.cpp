#include <stdio.h>
#include <unordered_set>

#define lim int(1e5)

using namespace std;

int numbers[lim + 1];
int distinct[lim + 1];
unordered_set<int> s;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        s.insert(numbers[i]);
        distinct[i] = s.size();
    }
    int q;
    while (m--) {
        scanf("%d", &q);
        printf("%d\n", distinct[q - 1]);
    }
}