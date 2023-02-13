#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    multiset<int> st;
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<int> a(st.begin(), st.end());
    for (int i = 0; i < 2 * n - 1; i++) {
        auto t = st;
        vector<pair<int, int>> ans;
        int x = a[i] + a[n * 2 - 1];
        int ok = 1;
        for (int j = 0; j < n; j++) {
            int d1 = *t.rbegin();
            auto e = t.find(x - d1);
            if (e == t.end() || e == prev(t.end())) {
                ok = 0;
                break;
            }
            int d2 = *e;
            t.erase(t.find(d1));
            t.erase(t.find(d2));
            ans.emplace_back(d1, d2);
            x = d1;
        }
        if (ok) {
            cout << "YES\n";
            cout << a[i] + a[2 * n - 1] << "\n";
            for (auto [i, j] : ans) {
                cout << i << " " << j << "\n";
            }
            return;
        }
    }
    cout << "NO\n";
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