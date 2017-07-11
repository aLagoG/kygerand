#define _CRT_SECURE_NO_DEPRECATE

#include <cctype>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

inline int itoa(int n) { return n + '0'; }

int main() {
    // infijo a posfijo
    stack<char> st;
    string in, res = "";
    unordered_map<char, char> ch;
    ch.insert({')', '('});
    ch.insert({']', '['});
    ch.insert({'}', '{'});
    getline(cin, in);
    bool last = false;
    for (auto c : in) {
        if (isdigit(c)) {
            res += c;
            last = true;
            continue;
        }
        if (last) {
            res += '_';
            last = false;
        }
        switch (c) {
            case ('('):
            case ('['):
            case ('{'):
                st.push(c);
                break;
            case ('}'):
            case (']'):
            case (')'):
                while (st.top() != ch[c]) {
                    res += st.top();
                    st.pop();
                }
                st.pop();
                break;
            case ('+'):
            case ('-'):
                while (!st.empty() && st.top() != '(' && st.top() != '{' &&
                       st.top() != '{') {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
                break;
            case ('*'):
            case ('/'):
            case ('%'):
                while (!st.empty() && st.top() != '(' && st.top() != '{' &&
                       st.top() != '{' && st.top() != '+' && st.top() != '-') {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
                break;
        }
    }
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    int a, b;
    in.clear();
    stack<int> nst;
    string nm = "";
    last = false;
    for (auto c : res) {
        if (isdigit(c)) {
            nm += c;
            last = true;
            continue;
        }
        if (last) {
            nst.push(stoi(nm));
            nm = "";
            last = false;
            continue;
        }
        switch (c) {
            case ('+'):
                a = nst.top();
                nst.pop();
                b = nst.top();
                nst.pop();
                nst.push(a + b);
                break;
            case ('-'):
                a = nst.top();
                nst.pop();
                b = nst.top();
                nst.pop();
                nst.push(a - b);
                break;
            case ('*'):
                a = nst.top();
                nst.pop();
                b = nst.top();
                nst.pop();
                nst.push(a * b);
                break;
            case ('/'):
                a = nst.top();
                nst.pop();
                b = nst.top();
                nst.pop();
                nst.push(a / b);
                break;
            case ('%'):
                a = nst.top();
                nst.pop();
                b = nst.top();
                nst.pop();
                nst.push(a % b);
                break;
        }
    }
    printf("%d\n", nst.top());
}