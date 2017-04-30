#include <cstdio>

using namespace std;

int main(){
	int exponent;
	scanf("%d", &exponent);

		if(exponent == 0){
			printf("0");
		}else if(exponent == 1){
			printf("3");
		}else if (exponent == 2){
			printf("17");
		}else if(exponent == 3){
			printf("77");
		}else if(exponent == 4){
			printf("377");
		}else if(exponent == 5){
			printf("1777");
		}else{

			if(exponent % 3 == 1){
				printf("3");
				for(int i = 0; i < ((exponent/3)*2); i++) printf("7");
			}else if(exponent % 3 == 2){
				printf("1");
				for(int i = 0; i < ( ((exponent+1)/3)*2 )-1; i++) printf("7");
			}else{
				printf("7");
				for(int i = 0; i < ((exponent/3)*2)-1; i++) printf("7");
			}
			
		}

}