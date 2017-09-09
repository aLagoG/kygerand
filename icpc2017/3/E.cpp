#include <stdio.h>
#include <cmath>


int main() {
    int n, a, b, c;
    
    int sum;
    while(scanf("%d", &n), n){

        sum = 0;
        for(a = 1; a <= n; a++){
            for(b = a; b <= n; b++){
                int c = (a*a)+(b*b);
                // printf("%d\n", c);
                int s = sqrt((a*a)+(b*b));
                if(s*s == c && c <= (n*n)){
                    sum++;
                }
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}