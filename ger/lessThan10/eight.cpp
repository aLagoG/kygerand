#include<stdio.h>

using namespace std;

int main(){
	int size = 20;
	
	int arr[size];
	for(int i = 0; i<20; i++) arr[i] = i;

	int n = 1 << size;
	for(int i = 0; i < n; i++){
		for(int j = 0; j<size; j++) if(i&(1<<j)) printf("%d ",arr[j]);
		printf("\n");
	}
}