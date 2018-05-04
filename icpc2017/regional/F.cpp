// 1.- join v with same b and f
// 2.- order in increasing order of f and decreasing of b
// 3.- maintain (segment or binary) tree that can get us the greatest possible
//      donation with the v that has already been processed and has a b
//      value smaller than the current one (this works because f is increasing
//      so no matter where we are either we use donations with smaller b + us or
//      donations with the same or greater b)

#include <stdio.h>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;

struct person {
    int b, f;
    ll d;
    person(int _b, int _f) {
        b = _b;
        f = _f;
    }
    bool operator<(const person &other) const {
        // order ascending by b and descending by f
        return b == other.b ? f > other.f : b < other.b;
    }
};

#pragma region tree

class FenwickTree {
   private:
    vector<ll> tree;

   public:
    FenwickTree(int n) {
        tree.resize(n + 1);
    }
    FenwickTree(vector<ll> &v) {
        int n = v.size();
        tree.resize(n + 1);
        for (int i = 0; i < n; i++) {
            update(i, v[i]);
        }
    }

    void update(int index, ll val) {
        index++;
        while (index < tree.size()) {
            tree[index] = max(tree[index], val);
            index += index & (-index);
        }
    }

    int query(int index) {
        index++;
        ll sum = 0;
        while (index) {
            sum = max(sum, tree[index]);
            index &= index - 1;
        }
        return sum;
    }
};

#pragma endregion

int main() {
    int n;
    scanf("%d", &n);
    map<person, ll> m;
    for (int i = 0; i < n; i++) {
        int b, f;
        ll d;
        scanf("%d %d %lld", &b, &f, &d);
        person p(b, f);
        m[p] += d;
    }
    vector<person> v;
    v.reserve(n);
    for (auto item : m) {
        v.push_back(item.first);
        v.back().d = item.second;
    }
    map<ll, ll> cm;
    for (auto p : v) {
        cm[p.f] = 0;
    }
    int cnt = 1;
    for (auto &v : cm) {
        v.second = cnt++;
    }
    for (auto &p : v) {
        p.f = cm[p.f];
    }
    n = v.size();
    int last;
    ll best = 0;
    FenwickTree f(cnt);
    for (int i = 0; i < n;) {
        last = v[i].b;
        while (i < n && v[i].b == last) {
            ll a = f.query(v[i].f - 1) + v[i].d;
            ll b = f.query(v[i].f);
            f.update(v[i].f, max(a, b));
            best = max(best, max(a, b));
            i++;
        }
    }
    printf("%lld\n", best);
}