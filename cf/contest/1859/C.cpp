#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cout << i << "---" << j << endl;
            ll tans = 0;
            set<int> st;
            for (int k = 1; k <= n; k++) {
                if (k == i)
                    continue;
                st.insert(k);
            }
            for (int k = n; k >= 1; k--) {
                if (k == j)
                    continue;
                auto it = st.upper_bound(i * j / k);
                if (it == st.begin()) {
                    tans = -1;
                    break;
                }
                tans += k * (*--it);
                // cout << k << " " << *it << endl;
                st.erase(it);
            }
            ans = max(ans, tans);
        }
    }
    cout << ans << "\n";
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