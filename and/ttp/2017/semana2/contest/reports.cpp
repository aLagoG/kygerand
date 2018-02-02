//3410
#include <stdio.h>
#include <string.h>

typedef unsigned long long ul;

ul yrs[2015];

int main(){
	int n;
	memset(yrs,0,sizeof yrs);
	scanf("%d",&n);
	ul y, a;
	while(n--){
		scanf("%llu %llu",&y,&a);
		yrs[y]+=a;
	}
	for(int i=0;i<2015;i++){
		if(yrs[i]){
			printf("%d %llu\n",i,yrs[i]);
		}
	}
}