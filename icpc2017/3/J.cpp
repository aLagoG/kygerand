#include <stdio.h>
#include <stack>

using namespace std;

int cnt(int i){
    int r = 0;
    while(i){
        i &= (i-1);
        r++;
    }
    return r;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        char w1[4];
        char w2[4];
        scanf(" %c%c%c%c %c%c%c%c",&w1[0], &w1[1], &w1[2], &w1[3], &w2[0], &w2[1], &w2[2], &w2[3]);
        stack<char> st;
        // 0 = i 1 = o
        for(int i=0;i<=0xff;i++){
            if(cnt(i)!=4){
                continue;
            }
            int idx = 0;
            int resIdx = 0;
            bool valid = 1;

            for(int j=7; j>=0 && idx<4 && valid && resIdx<4 ;j--){
                bool op = i&(1<<j);
                if(op){
                    if(st.top() != w2[resIdx]){
                        valid = 0;
                    }
                    st.pop();
                }else{
                    st.push(w1[idx++]);
                }
            }
            if(valid){
                printf(i&(1<<7)?"o":"i");
                for(int j=1;j<8;j++){
                    printf(i&(1<<j)?" o":" i");
                }
                printf("\n");
            }
        }
    }
}