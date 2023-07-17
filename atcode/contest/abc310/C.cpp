#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    set<string> st;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        auto t = s;
        reverse(t.begin(), t.end());
        if (st.count(t) || st.count(s))
            continue;
        st.insert(s);
    }
    cout << st.size() << "\n";
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