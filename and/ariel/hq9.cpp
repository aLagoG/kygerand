#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    bool d = 0;
    for(auto& c: s){
        if(c == 'H' || c == 'Q' || c == '9'){
            d = 1;
            break;
        }
    }
    cout << (d ? "YES" : "NO") << endl;
}
