//2658
#include <stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b, s;
		scanf("%d %d %d",&a,&b,&s);
		int n = 2*s/(a+b);
		int d = (b-a)/(n-5);
		int st = a - 2*d;
		printf("%d\n",n);
		for(int i=0;i+1<n;i++){
			printf("%d ",st+(i*d));
		}
		printf("%d\n",st+(n-1)*d);
	}
}
