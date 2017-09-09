#include<regex.h>
#include<stdio.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	char word[n];

	scanf("%s", word);
	regex r ("/([A-Za-z][0-9][0-9])/");
	regex_replace(word, r);

	printf("%s", word);
}