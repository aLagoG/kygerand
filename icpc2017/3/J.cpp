#include <stdio.h>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char w1[4];
        char w2[4];
        // char res[4];
        scanf(" %c%c%c%c %c%c%c%c",&w1[0], &w1[1], &w1[2], &w1[3], &w2[0], &w2[1], &w2[2], &w2[3]);
        stack<char> st;
        // 0 = i 1 = o
        char mask[] = {'i', 'i', 'i', 'i', 'o', 'o', 'o', 'o'};
        stack<char> stck;
        printf("Output for %c%c%c%c %c%c%c%c\n[\n",w1[0], w1[1], w1[2], w1[3], w2[0], w2[1], w2[2], w2[3] );

        do{
            // printf(" %c%c%c%c %c%c%c%c\n",mask[0], mask[1], mask[2], mask[3], mask[4], mask[5], mask[6], mask[7]);
            bool valid = true;
            int i = 0, j = 0;
            for(auto c: mask){
                if(c == 'i'){
                    stck.push(w1[i++]);
                }else{
                    if(!stck.empty()){
                        if((stck.top()) == w2[j]){
                            j++;
                            stck.pop();
                        }else{
                            valid = false;
                            break;
                        }
                    }else{
                        valid = false;
                        break;
                    }
                }
            }
            if(valid){
                printf("%c %c %c %c %c %c %c %c\n",mask[0], mask[1], mask[2], mask[3], mask[4], mask[5], mask[6], mask[7]);
                // printf("%c%c%c%c\n",res[0], res[1], res[2], res[3]);
            }

        }while(next_permutation(mask,mask+8));

        printf("]\n");
    }
}
