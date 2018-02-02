//2204
#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=2;i<=n;i++){
			printf("%d ",i);
		}
		printf("%d\n", 1);
	}
}