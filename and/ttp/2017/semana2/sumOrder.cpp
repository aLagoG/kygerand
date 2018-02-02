//2789
#include <stdio.h>

using namespace std;

int nums[4] = {0,0,0,0};

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		nums[n]++;
	};
	int count = nums[1]+nums[2]+nums[3];
	int act = 0;
	for(int i=1;i<4;i++){
		while(nums[i]--){
			if(++act<count){
				printf("%d+",i);
			}else{
				printf("%d",i);
			}
		}
	}
}