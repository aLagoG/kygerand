#include <stdio.h>
#include <unordered_map>
#include <vector>

using namespace std;

int pow(int x, unsigned long long y, int m) {
    int res = 1;
    x %= m;
    while (y) {
        if (y & 1) {
            res = (res * x) % m;
        }
        y >>= 1;
        x = (x * x) % m;
    }
    return res;
}

int main() {
    int N;
    scanf("%d", &N);
    vector<int> v;
    unordered_map<int, int> mp;
    while (N--) {
        v.clear();
        mp.clear();
        int a, b, i;
        unsigned long long n;
        unsigned long long mult = 1;
        scanf("%d %d %llu", &a, &b, &n);

        bool cycle = false;
        a *= 10;
        for (i = 0; i < n; i++) {
            // printf("Current a = %d and b = %d\n",a,b);
            if (mp.find(a) != mp.end()) {
                // printf("Found cycle at %d\n",i);
                cycle = true;
                break;
            } else {
                // printf("Adding to map key %d at index %d\n",a,i);
                mp[a] = i;
            }

            if ((a / b) == 0)
                v.push_back(v.size() ? v[v.size() - 1] : 1);
            else
                v.push_back((v.size() ? v[v.size() - 1] : 1) * (a / b));

            if (!(a % b)) {  // If perfect fraction
                break;
            }
            a = (a % b) * 10;
        }

        // printf("----------------\n");
        // for(int j = 0; j<v.size();j++)
        //     printf("%3d",v[j]);
        // printf("\n");

        // printf("----------------\n");
        // for(auto it = mp.begin(); it!=mp.end();it++)
        //     printf("%3d with %3d\n",it->first,it->second);
        // printf("\n");

        if (cycle) {
            int cyclelen = i-mp[a];
            // printf("cyclelen %d\n",cyclelen);
            int cyclestart = mp[a];
            // printf("cyclestart %d\n",cyclestart);
            int numberoftimes = (n-mp[a])/cyclelen;
            // printf("numberoftimes %d\n",numberoftimes);
            int cycleend = i-1;
            // printf("cycleend %d",cycleend);
            // printf("Found cycle from %d to %d",mp[i],i);
            // printf("-----------\n");
            // printf("Got %d from %d^%d multiplying by %d\n",pow(v[v.size() - 1], n / i,188888881) * v[n % i],v[v.size()],n/i,v[n%i]);
            printf("%d\n",
                   pow(v[v.size() - 1]/v[cyclestart-1], (numberoftimes),188888881) * v[cyclestart + ((n-cyclestart)%cyclelen)]/v[cyclestart-1]);
        } else {
            // printf("-----------\n");
            // printf("Found without finding cycle\n");
            printf("%d\n", v[v.size() - 1]%188888881);
        }
    }
}