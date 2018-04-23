#include <stdio.h>

typedef unsigned long long ull;

int main(){
    int n;
    while(scanf("%d", &n),n>-1){
        ull m=0,f=1, tmp;
        while(n--){
            tmp = f;
            f+=m;
            m+=tmp;
        }
        printf("%llu %llu", m, m+f);
    }
}