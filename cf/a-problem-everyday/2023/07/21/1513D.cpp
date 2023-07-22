
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, p;
    cin >> n >> p;
    vector<int> a(n);
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.emplace(a[i], i);
    }
    ll ans = 0;
    vector<int> con(n, 0);  // con[i] i是否与右侧某个相连
    for (auto [i, j] : st) {
        if (i >= p)
            continue;
        int p = j;
        while (p > 0) {
            if (con[p - 1] || a[p - 1] % i)
                break;
            con[p - 1] = 1;
            ans += i;
            p--;
        }
        p = j;
        while (p < n - 1) {
            if (con[p] || a[p + 1] % i)
                break;
            con[p] = 1;
            ans += i;
            p++;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (!con[i])
            ans += p;
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
