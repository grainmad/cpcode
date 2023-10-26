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
    vector<int> a(n), c(n);
    for (auto& i : a)
        cin >> i;
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (st.count(a[i]) == 0)
            c[i]++;
        if (i)
            c[i] += c[i - 1];
        st.insert(a[i]);
    }
    st.clear();
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (st.count(a[i]) == 0) {
            ans += c[i];
        }
        st.insert(a[i]);
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