
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 100005
#define MOD 1000000007
using namespace std;

int n;
ll h[N], w[N], pw[N];

ll f(ll x) {
    return x * (x + 1) / 2 % MOD;
}

ll seg(int l, int r) {  // [l, r]
    return (pw[r] - pw[l - 1] + MOD) % MOD;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        pw[i] = (pw[i - 1] + w[i]) % MOD;
    }
    vector<int> st;
    vector<int> l_l(n + 1, 0), r_le(n + 1, n + 1);
    for (int i = 1; i <= n; i++) {
        while (st.size() && h[st.back()] >= h[i]) {  // 严增
            r_le[st.back()] = i;
            st.pop_back();
        }
        if (st.size())
            l_l[i] = st.back();
        st.push_back(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f(w[i]) * f(h[i]) % MOD;
        ans %= MOD;
        ans += seg(l_l[i] + 1, i) * seg(i, r_le[i] - 1) % MOD * f(h[i]) % MOD;
        ans %= MOD;
        ans = (ans - f(h[i]) * seg(i, i) % MOD * seg(i, i) % MOD + MOD) % MOD;
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
