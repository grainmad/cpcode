#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, x;
    cin >> n >> x;
    set<ll> st;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        st.insert(a);
        if (st.count(a - x) || st.count(a + x))
            ok = true;
    }
    cout << (ok ? "Yes\n" : "No\n");
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