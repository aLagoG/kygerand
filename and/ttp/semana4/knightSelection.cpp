//3355
#include <stdio.h>
#include <string.h>

#define N 3002

int factors[N];
int n;

void cribaE(){
	memset(factors,0,sizeof factors);
	int p = 2;
	while(p<n){
		for(int i=2*p;i<=n;i+=p){
			factors[i]++;
		}
		while(p<n&&factors[++p]);
	}
}

int main(){
	scanf("%d",&n);
	cribaE();
	int r = 0;
	for(int i=6;i<=n;i++){
		if(factors[i]==2){
			r++;
		}
	}
	printf("%d\n",r);
}