#include <iostream>
#include <vector>

using namespace std;

/*
reference:
http://www.techiedelight.com/longest-increasing-subsequence/
https://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming
*/

// Longest Increasing Subsequence O(nLogn)
// RETURNS THE JUST LENGTH
// I DONT UNDERSTAND THIS YET GODDAMMIT I HATE MYSELF
// WUBBA LUBBA DUB DUB

int CeilIndex(vector<int> &v, vector<int> &k, int l, int r, int key) {
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (k[v[m]] >= key) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

vector<int> LongestIncreasingSubsequenceLength(vector<int> &v) {
    int n = v.size();

    // tail is used to store the index of the weird values list
    vector<int> tail(n);
    // parent[i] stores the index of the element that is just before the one at
    // i in the lis
    vector<int> parent(n);
    // the first element of the lis is always the first element
    tail[0] = 0;
    int length = 1;
    for (size_t i = 1; i < n; i++) {
        // if the current element is the smallest so far
        if (v[i] < v[tail[0]]) {
            // change the tail to show it
            tail[0] = i;
            // if the current element is greater than the last in the lis
        } else if (v[i] > v[tail[length - 1]]) {
            // store the index of the last one
            parent[i] = tail[length - 1];
            // store its index as the new last
            tail[length++] = i;
        } else {
            // find the first element that is >= than the current one
            int idx = CeilIndex(tail, v, -1, length - 1, v[i]);
            // store the curren elements parent as the one before
            parent[i] = tail[idx - 1];
            // change that element for the current one
            tail[idx] = i;
        }
    }

    // reconstruct the list by "recursively" getting the parent of the last one
    vector<int> lis(length);
    int last = tail[length - 1];
    lis[length - 1] = v[last];
    while (length--) {
        last = parent[last];
        lis[length - 1] = v[last];
    }

    return lis;
}

int main() {
    // vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};
    vector<int> v{1, 2, 1, 4};
    // cout << "Length of Longest Increasing Subsequence is "
    //      << LongestIncreasingSubsequenceLength(v) << endl;
    auto res = LongestIncreasingSubsequenceLength(v);
    for (auto x : res) {
        cout << x << endl;
    }
}

/*
and - this code does the exact same but is more concise thanks to the usage of
std::set

#include <set>
int LISLength(vector<int> &v) {
    int n = v.size();
    set<int> s;
    for (int i = 0; i < n; i++) {
        auto res = s.insert(v[i]); //O(log(n))
        if (res.second) {
            auto it = res.first;
            if (++it != s.end()) {
                s.erase(it); //O(1)
            }
        }
    }
    return s.size();
}

*/