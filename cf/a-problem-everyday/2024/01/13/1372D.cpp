
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n;
    cin >> n;
    vector<ll> a(n*2+1), p(n*2+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];
    }
    for (int i=1; i<=2*n; i++) {
        if (i>=2) p[i] = p[i-2];
        p[i] += a[i];
    }
    ll ans = 0;
    for (int i=n; i<=2*n; i++) {
        ans = max(ans, p[i]-p[max(0, i-n-1)]);
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
