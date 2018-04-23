#include <stdio.h>

int gcd(int a, int b){
	int res = 1;
	int d =0;
	if(a==b){
		return a;
	}
	while(!(a&1)&&!(b&1)){
		a >>= 1;
		b >>= 1;
		res = 1<<(++d);
	}
	while(a!=b){
		if(!(a&1)){
			a >>= 1;
		}else if(!(b&1)){
			b >>= 1;
		}else if(a>b){
			a = (a-b)>>1;
		}else{
			b = (b-a)>>1;
		}
	}
	return a*res;
}

int main(){
    int n;
    scanf("%d", &n);
    int res = 0;
    for(int i=1;i<n;i++){
        if(gcd(i,n)==1){
            res++;
        }
    }
    printf("%d\n", res);
}