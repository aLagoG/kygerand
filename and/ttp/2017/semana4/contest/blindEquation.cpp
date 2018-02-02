#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long double ld;
typedef unsigned long long ul;

ld a,b,c,d,e,f;

inline long double fun(ld x){
	return a*x*x*x*x+b*x*x*x+c*x*x+d*x+e-f;
}

inline long double der(ld x){
	return 4*a*x*x*x+3*b*x*x+2*c*x+d;
}

bool correct(ld x){
	ul tmp = ul(x);
	return ul(a)*tmp*tmp*tmp*tmp+ul(b)*tmp*tmp*tmp+ul(c)*tmp*tmp+ul(d)*tmp+ul(e)-ul(f) == 0;
}

int main(){
	while(scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&a,&b,&c,&d,&e,&f)!=EOF){
		ld x =(ld)sqrt(sqrt(f-e));
		ld last = 0;
		while(abs(x-last)>0.09){
			last = x;
			x -= fun(x)/der(x);
		}
		//hacer un metodo que busque uno arriba, uno abajo y imprima la solucion
		if(correct(x)){
			printf("%llu\n",ul(x));
		}else{
			printf("-1\n");
		}
		
	}
}