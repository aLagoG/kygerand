//1551
#include <iostream>

using namespace std;

int main(){
	int a,b,c,d=1;
	while(scanf("%d %d %d",&a,&b,&c)==3){
		cout << "Case "<<d++<<": ";
		if(a+b==c){
			cout << a << "+" << b << "=" << c << "\n";
		}else if(a==b+c){
			cout << a << "=" << b << "+" << c << "\n";
		}else if(a-b==c){
			cout << a << "-" << b << "=" << c << "\n";
		}else if(a==b-c){
			cout << a << "=" << b << "-" << c << "\n";
		}else if(a*b==c){
			cout << a << "*" << b << "=" << c << "\n";
		}else if(a==b*c){
			cout << a << "=" << b << "*" << c << "\n";
		}else if(a/b==c&&a%b==0){
			cout << a << "/" << b << "=" << c << "\n";
		}else if(a==b/c&&b%c==0){
			cout << a << "=" << b << "/" << c << "\n";
		}
	}
}