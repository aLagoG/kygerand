//3430
#include <iostream>
#include <string>

using namespace std;

string in;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	getline(cin,in);
	int a=-1,b,n=in.length();
	for(int i=n-1;i>=0;i--){
		if(in[i]=='('){
			a = i;
			in.erase(a,1);
			for(int j=a;j<n;j++){
				if(in[j]==')'){
					b = j--;
					in.erase(b--,1);
					char tmp;
					while(b>a){
						tmp = in[a];
						in[a++] = in[b];
						in[b--] = tmp;
					}
					break;
				}
			}
		}
	}
	cout << in << "\n";
}