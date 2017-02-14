//1103
#include <stdio.h>

int main(){
	int cn[5] = {1, 5, 10, 25, 50};
	int ct[7490];
	for(int i=0;i<7490;i++){
		ct[i]=1;
	}
	for(int i=1;i<5;i++){
		for(int j=cn[i];j<7490;j++){
			ct[j] += ct[j-cn[i]];
		}
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n", ct[n]);
	}
}
