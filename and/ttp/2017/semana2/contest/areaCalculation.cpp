//3127
#include <stdio.h>
#include <math.h>

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Case %d: ",i+1);
		int v;
		scanf("%d",&v);
		int v17 = v/17;
		if(v17<1){
			if(v<5){
				printf("2\n");
			}else if(v>=5&&v<11){
				printf("3\n");
			}else{
				printf("4\n");
			}
			continue;
		}
		int v3 = (v17+1)*3;
		int ran[] = {v17*17,v17*17+6,(v17+1)*17-6};
		if(v>=ran[0]&&v<ran[1]){
			printf("%d\n", v3-1);
		}else if(v>=ran[1]&&v<ran[2]){
			printf("%d\n", v3);
		}else{
			printf("%d\n",v3+1);
		}
	}
}