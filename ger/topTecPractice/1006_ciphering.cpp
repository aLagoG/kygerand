#include <cstdio>
using namespace std;

void switcheroo(char* line, char* nline, int start, int end, int idx){
	int mid = (((end-start)+1)/2);
	if(mid == 0) return;
}

int main(){
	char c;
	char line[20001];
	char nline[20001];
	int i = 0;
    while(scanf("%c", &c) != EOF){
    	
    	if(c == '\n'){
    		//switcheroo
    		i = 0;
    	}else{
    		if( (c>='a' && c<='z') || (c>='A' && c<='Z') ){
    			switch(c){
    				case 'a':
    					c = 'z';
    					break;
    				case 'A':
    					c = 'Z';
    					break;
    				default: c = c-1;
    			}
    		}
    	}
    	//printf("%c", c);
    	line[i] = c;

    	i++;
    }
 	return 0;
}
