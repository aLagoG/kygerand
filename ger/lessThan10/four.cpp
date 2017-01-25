#include <stdio.h>
#include <algorithm>
#include <vector> 
#include <../competitive.h>
using namespace std;

int main(){
    int n;
    vi arr (n,0);
    scanf("%d", &n);
    while(n--) scanf("%d", arr[n]);
    sort(ALL(arr));
    arr.resize(unique(ALL(arr))-arr.begin());
    for(i = 0; i<(int)arr.size(); i++) printf("%d\n" arr[i]);
    
    return 0;
}