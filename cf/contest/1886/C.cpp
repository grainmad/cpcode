#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    ll p;
    cin >> p;
    ll sz = s.size();
    while (p > sz) {
        p -= sz;
        sz--;
    }
    sz = s.size() - sz;
    string st;
    for (auto i : s) {
        while (sz > 0 && st.size() && st.back() > i) {
            st.pop_back();
            sz--;
        }
        st.push_back(i);
    }
    cout << st[p - 1];
}

int main() {
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}