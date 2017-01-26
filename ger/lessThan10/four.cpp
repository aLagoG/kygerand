#include <stdio.h>
#include <algorithm>
#include <vector> 
#include "../../competitive.h"

int main(){
    int n;
    scanf("%d", &n);
    vi arr (n,0);
    while(n--) scanf("%d", &arr[n]);
    sort(ALL(arr));
    arr.resize(unique(ALL(arr))-arr.begin());
    for(int i = 0; i<((int)arr.size()); i++) printf("%d\n", arr[i]);
    return 0;
}
