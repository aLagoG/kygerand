#include <stdio.h>

int arr[100001];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
        long sum = 0;
        int max = -1;
        int max2 = -1;
        int window = 0;
        int stdsize = n / k;
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
            if (i < stdsize) {
                window += arr[i];
            } else {
                if (max2 < window) {
                    max2 = window;
                }
                window -= arr[i - stdsize];
                window += arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        int a = max, b = sum / k, c = max2;
        while (1) {
            int gcount = 1;
            int localMax = -1;
            int curr = 0;
            for (int i = 0; i < n && gcount <= k; i++) {
                if (curr + arr[i] <= b) {
                    curr += arr[i];
                } else {
                    if (curr > localMax) {
                        localMax = curr;
                    }
                    curr = arr[i];
                    gcount++;
                }
            }
            if (gcount < k) {
                c = b;
                b = (b - a) / 2 + a;
            } else if (gcount > k) {
                a = b;
                b = (c - b) / 2 + b;
            } else {
                printf("%d\n", localMax);
                break;
            }
    }
}
