#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> c(n + 1), f(n + 1, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        c[x]++;
    }
    vector<pair<ll, ll>> st;
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) {
            if (st.empty())
                break;
            f[i] = i - st.back().first;
            if (--st.back().second == 0)
                st.pop_back();
        } else
            f[i] = 0;
        if (c[i] > 1) {
            st.emplace_back(i, c[i] - 1);
        }
    }
    for (int i = 1; i < n; i++) {
        if (f[i] != -1)
            f[i] += f[i - 1];
    }
    cout << c[0] << " ";
    for (int i = 1; i <= n; i++) {
        if (f[i - 1] < 0) {
            cout << "-1 ";
        } else {
            cout << f[i - 1] + c[i] << " ";
        }
    }
    cout << "\n";
}
int main() {
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