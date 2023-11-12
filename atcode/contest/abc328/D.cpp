#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    string st;
    for (auto i : s) {
        st.push_back(i);
        if (st.size() >= 3 && st.substr(st.size() - 3) == "ABC") {
            st.pop_back();
            st.pop_back();
            st.pop_back();
        }
    }
    cout << st << "\n";
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