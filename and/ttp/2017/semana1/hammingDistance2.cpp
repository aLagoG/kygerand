//2014
#include <iostream>
#include <string>

using namespace std;

int main(){
	int n, d;
	cin >> n;
	for(int i=1;i<=n;i++){
		string b;
		cin >> b >> d;
		string c(b);
		int dd = 0;
		for(int j=0;dd<d&&j<b.size();j++){
			if(b[j]=='1'){
				c[j]='0';
				dd++;
			}
		}
		for(int j=b.size()-1;dd<d&&j>=0;j--){
			if(b[j]=='0'){
				c[j]='1';
				dd++;
			}
		}
		cout << "Case #" << i << ": " << c << "\n";
	}
}