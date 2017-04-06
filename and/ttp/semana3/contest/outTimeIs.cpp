//2718
#include <stdio.h>

int main(){
	int h2,m2,h1,m1;
	scanf("%d:%d %d:%d",&h2,&m2,&h1,&m1);
	int rh,rm;
	if(m2<m1){
		rm = 60-m1+m2;
		h1++;
	}else{
		rm = m2-m1;
	}
	if(h2<h1){
		rh = 24-h1+h2;
	}else{
		rh = h2-h1;
	}
	printf("%02d:%02d\n",rh,rm);
}