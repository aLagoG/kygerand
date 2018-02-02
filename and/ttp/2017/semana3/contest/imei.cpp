//3415
#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	char c;
	scanf("%c",&c);
	while(t--){
		int sum = 0;
		for(int i=0;i<14;i++){
			scanf("%c",&c);
			// printf("%d ",((int) c-'0')*(i&1?2:1));
			int tmp = ((int) c-'0')*(i&1?2:1);
			sum+= tmp>9?tmp-9:tmp;
		}
		// printf("%d\n",sum);
		scanf("%c",&c);
		sum%=10;
		if(!sum){
			printf("0\n");
		}else{
			printf("%d\n",10-sum);
		}
	}
}