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
        int i, j;
        for (i = 0; i < n; i++) lis[i] = 1;
        for (i = 1; i < n; i++) {
            for (j = 0; j < i; j++)
                if (arr[i] >= arr[j] && lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
        }

        for(i=0;i<n;i++)lis2[i]=0;
        for (i = n-2; i > 0; i--) {
            for (j = n-1; j > i; j--){
                if (arr[i] >arr[j] && lis2[i] < lis2[j] + 1)
                    lis2[i] = lis2[j] + 1;
            }
        }
        int max=lis[0]+lis2[0];
        for(i=1;i<n;i++){
          lis[i]=lis[i]+lis2[i];
          if(max<lis[i])max=lis[i];
        }
        free(lis);
        free(lis2);
        printf("%d\n", max);
    }
}
