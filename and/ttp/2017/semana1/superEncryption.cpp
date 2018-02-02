//2623
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	string line;
	cin >> line;
	reverse(line.begin(),line.begin()+line.size()/2);
	reverse(line.begin()+line.size()/2+(line.size()%2!=0?1:0),line.end());
	cout <<  line;
}