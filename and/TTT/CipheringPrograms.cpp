//1006
#include <stdio.h>

using namespace std;

char letrBefore(char in);

void recPrint(char* arr,int min, int max){
	if(min>=max){
		return;
	}
	printf("%c", arr[(max+1)/2]);
	recPrint(arr, min, (max+1)/2-1);
	recPrint(arr, (max+1)/2+1, max);
}

int main(){
	char line[20001];
	int i=0;
	while(scanf("%c",&line[i])!=EOF){
		printf("%c",line[i]);
		if(line[i]=='\n'){
			recPrint(line, 0, i+1);
			i = 0;
		}else{
			line[i] = letrBefore(line[i]);
			i++;
		}
	}
}

char letrBefore(char in){
	if((in>'z'||in<'a')&&(in>'Z'||in<'A')){
		return in;
	}
	switch(in){
	case ('a'):
		return 'z';
	case ('A'):
		return 'Z';
	default:
		return in-1;
	}
}
