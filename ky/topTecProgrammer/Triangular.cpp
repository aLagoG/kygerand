#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
	long double n;
	long double f1,f2,fin1,fin2,check;
	while(scanf("%Lf", &n),n){
		n=-n*2;
		check=sqrt(1-4*n);
		if(check>0){
			f1=(-1+sqrtl(1-4*n))/2;
			f2=(-1-sqrtl(1-4*n))/2;
			modfl(f1,&fin1);
			modfl(f2,&fin2);
			
			if(f1>0&&f2<1){
				if(fin1==ceil(f1)){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}else if(f2>0&&f1<1){
				if(fin2==ceil(f2)){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}else if(f2>0&&f1>0){
				if(fin1==ceil(f1)||fin2==ceil(f2)){
					printf("YES\n");
				}else{
					printf("NO\n");
				}
			}
			
		}else{
			printf("NO\n");
		}
	}
}