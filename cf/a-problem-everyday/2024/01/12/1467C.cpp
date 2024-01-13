
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<ll> a(n1), b(n2), c(n3);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    for (auto& i:c) cin >> i;
    ll ma = *min_element(a.begin(), a.end()), sa = accumulate(a.begin(), a.end(), 0LL);
    ll mb = *min_element(b.begin(), b.end()), sb = accumulate(b.begin(), b.end(), 0LL);
    ll mc = *min_element(c.begin(), c.end()), sc = accumulate(c.begin(), c.end(), 0LL);
    ll ans = 0;
    ans = max(ans, sa+sb+sc-2*(ma+mb+mc-max({ma,mb,mc})));
    ans = max(ans, sa+sb+sc-2*(min({sa,sb,sc})));
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
