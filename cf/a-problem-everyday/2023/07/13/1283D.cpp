
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    set<ll> st;
    queue<pair<ll, ll>> q;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        st.insert(x);
        q.emplace(x, 0);
    }
    ll ans = 0;
    vector<ll> ansl;
    while (ansl.size() != m) {
        auto [p, v] = q.front();
        q.pop();
        if (!st.count(p - 1)) {
            ansl.push_back(p - 1);
            ans += v + 1;
            st.insert(p - 1);
            q.emplace(p - 1, v + 1);
        }
        if (ansl.size() == m)
            break;
        if (!st.count(p + 1)) {
            ansl.push_back(p + 1);
            ans += v + 1;
            st.insert(p + 1);
            q.emplace(p + 1, v + 1);
        }
    }
    cout << ans << "\n";
    for (ll i : ansl) {
        cout << i << " ";
    }
    cout << "\n";
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
