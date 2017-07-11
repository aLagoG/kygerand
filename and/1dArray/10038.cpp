#include <stdio.h>
#include <string.h>

#define abs(x) (x > 0 ? x : -1 * (x))
#define N 3002

bool nums[N];

bool is(int n) {
    for (int i = 1; i < n; i++) {
        if (!nums[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        memset(nums, 0, sizeof nums);
        int last, now;
        scanf("%d", &last);
        for (int i = 1; i < n; i++) {
            scanf("%d", &now);
            nums[abs(last - now)] = 1;
            last = now;
        }
        if (n == 1 || is(n)) {
            printf("Jolly\n");
        } else {
            printf("Not jolly\n");
        }
    }
}