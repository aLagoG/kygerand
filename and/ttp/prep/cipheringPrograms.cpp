//1006
#include <iostream>
#include <string>

using namespace std;

string line;
string res;

void letrBefore(){
	for(int i=0;i<line.size();i++){
		if((line[i]>'z'||line[i]<'a')&&(line[i]>'Z'||line[i]<'A')){
			continue;
		}
		switch(line[i]){
		case ('a'):
			line[i] = 'z';
			break;
		case ('A'):
			line[i] = 'Z';
			break;
		default:
			line[i] = line[i]-1;
			break;
		}
	}
}

void recBuild(int idx, int min, int max){
	if(min>max){
		return;
	}
	int val = max-min;
	res[val/2+min] =  line[idx];
	recBuild(idx+1, min, val/2+min-1);
	recBuild(idx+1+val/2, val/2+min+1, max);
}

int main(){
	ios_base::sync_with_stdio(false);
	int i=0;
	while(getline(cin,line)){
		res = string(line.size(),' ');
		letrBefore();
		recBuild(0,0,res.size()-1);
		cout << res << endl;
	}
}