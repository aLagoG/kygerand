#include <iostream>
#include <set>
#include <cmath>

using namespace std;

const int MAXN = int(1e5+5);
typedef pair<int,double> pid;

struct r_compare {
    bool operator()(const pid& l, const pid& r) const {
        return l.first * l.second < r.first * r.second;
    }
};

int n;
double w;
set<pid, r_compare> s;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(12);
    cin >> n >> w;
    int c;
    double r;
    for(int i=0;i<n;i++){
        cin >> c >> r;
        s.emplace(c,r);
    }
    double res = 0;
    for(auto g : s){
        res += g.first * w;
        w *= g.second;
    }
    cout << res << '\n';
}

