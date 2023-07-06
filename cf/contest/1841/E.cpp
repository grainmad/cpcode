#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<pair<int, int>> a;
set<int> st;
void sol() {
    a.clear();
    ll n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.emplace_back(x, i);
    }
    sort(a.rbegin(), a.rend());
    cin >> m;
    vector<ll> cnt(n + 1);  // cnt[i] 长度为i的段
    cnt[n] = n;
    st.clear();
    st.insert(-1), st.insert(n);
    for (auto [i, j] : a) {
        auto it = st.lower_bound(j);
        int r = *it, l = *--it;
        int len = r - l - 1;
        cnt[len] -= i;
        cnt[j - l - 1] += i;
        cnt[r - j - 1] += i;
        st.insert(j);
    }
    ll ans = 0;
    for (int i = n; i >= 1 && m > 0; i--) {
        if (m >= cnt[i] * i) {
            ans += cnt[i] * (i - 1);
            m -= cnt[i] * i;
        } else {
            ans += m / i * (i - 1) + max(0LL, m % i - 1);
            m = 0;
        }
    }
    cout << ans << endl;
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