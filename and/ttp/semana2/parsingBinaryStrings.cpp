//2858
#include <stdio.h>


int main(){
	char c;
	unsigned long long md = 1000000007;
	unsigned long long n = 0;
	bool num = false;
	while(scanf("%c",&c)!=EOF){
		if(c<='z'&&c>='a'){
			if(num){
				printf("%llu",n);
				n = 0;
				num = false;
			}
			printf("%c",c);
			continue;
		}
		num = true;
		if(c=='1'){
			n*=2;
			n++;
			n%=md;
		}else if(c=='0'){
			n*=2;
			n%=md;
		}
	}
	if(num){
		printf("%llu",n);
		n = 0;
	}
	printf("\n");
}