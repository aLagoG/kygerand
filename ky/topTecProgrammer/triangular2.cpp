#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	long long n;
	while(scanf("%lld", &n),n){
		if(n<1){
			printf("NO\n");
		}else if(((long long)sqrt(2*n)*(long long)(sqrt(2*n)+1))/2==n){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}