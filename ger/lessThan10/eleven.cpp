#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<math>

using namespace std;

stack<int> postfix;
stack<int> st;

int num(int x){return x-48;}

void postfixMake(int x, bool operator){
	int a, b, temp;
	if(operator){
		a = postfix.pop();
		b = postfix.pop();
		switch(x){
			case '^':
				temp = pow(a,b);
				break;
			case '*':
				temp = a*b;
				break;
			case '/':
				temp = a/b;
				break;
			case '+':
				temp = a+b;
				break;
			case '-':
				temp = a-b;
		}
	}
}


int main(){
	int prty[95];

	prty[94] = 3;
	prty[42] = 2;
	prty[47] = 2;
	prty[43] = 1;
	prty[45] = 1;

	string infix;
	getline(cin, infix);

	for(auto c: infix){
		if(47 <= c && c <= 57){
			postfixMake(x, false);
		}else{

		}
	}


	//cout << infix << "\n";
}