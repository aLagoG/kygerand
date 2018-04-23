#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct {
    int start;
    int end;
    int value;
} order;

bool operator<(const order a, const order b) {
    return a.end < b.end;
}

order orders[10001];
int dp[10001];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int duration;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &orders[i].start, &duration, &orders[i].value);
            orders[i].end = orders[i].start + duration;
        }
        sort(orders, orders + n);
        for (int i = 0; i < n; i++) dp[i] = orders[i].value;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (orders[j].end > orders[i].start) {
                    break;
                }
                if (dp[j] + orders[i].value > dp[i]) {
                    dp[i] = dp[j] + orders[i].value;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        printf("%d\n", max);
    }
}