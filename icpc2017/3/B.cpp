#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int* arr = (int*)malloc(sizeof(int) * n);
        int* lis = (int*)malloc(sizeof(int) * n);
        int* lis2 = (int*)malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int i, j, max = 0;
        for (i = 0; i < n; i++) lis[i] = 1;
        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++)
                if (arr[i] >= arr[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        }
        // for(int k=0;k<n;k++){
        //     printf("%d", lis[k]);
        // }
        // printf("\n\n");
        for (i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) lis2[k] = lis[i];
            for (int k = i + 1; k < n; k++) {
                for (int z = i; z < k; z++)
                    if (arr[k] < arr[z] && lis2[k] < lis2[z] + 1)
                        lis2[k] = lis2[z] + 1;
            }
            for (int k = 0; k < n; k++) {
                // printf("%d", lis2[k]);
                if (max < lis2[k]) {
                    max = lis2[k];
                }
            }
            // printf("\n");
        }
        free(lis);
        printf("%d\n", max);
    }
}
