#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int lis[n];
        int lds[n];
        //Base case for LIS and LDS, LDS starts at 0 because it adds up and from that start space, itself doesnt count.
        for(int i=0;i<n;i++) lis[i]=1;
        for(int i=0;i<n;i++) lds[i]=0;

        //Typical LIS
        for(int i=1;i<n;i++){
          for(int j=0;j<i;j++){
            if(arr[j]<=arr[i] && lis[j]+1>lis[i]){
              lis[i]=lis[j]+1;
            }
          }
        }

        //Typical LDS
        for (int i=n-2; i>=0; i--){
          for (int j=n-1; j>i; j--){
            if(arr[i] >arr[j] && lds[i] < lds[j] + 1){
              lds[i]=lds[j]+1;
            }
          }
        }

        //Find max after adding the two values
        int max=lis[0]+lds[0];
        for(int i=1;i<n;i++){
          if(lis[i]+lds[i]>max){
            max=lis[i]+lds[i];
          }
        }

        printf("%d\n", max);
    }
}
