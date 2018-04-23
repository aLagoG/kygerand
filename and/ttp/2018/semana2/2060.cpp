#include <stdio.h>

int main(){
    int n,k,res,sum;
    while(scanf("%d",&n),n>-1){
        res = 0;
        sum = 0;
        while(n--){
            scanf("%d",&k);
            sum += k;
            if(!(sum%100)){
                res++;
                sum = 0;
            }
        }
        printf("%d\n",res);
    }
}