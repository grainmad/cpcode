#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;

void sol() {
    int n, mn = 0;
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=n; i>=1; i--) {
        a[i-1] = min(a[i-1], a[i]);
        a[i] -= a[i-1];
    }
    int k;
    cin >> k;
    int ans = INF;
    for (int i=1; i<=n; i++) {
        if (a[i]) ans = min(ans, k/a[i]);
        k -= ans*a[i];
        cout << ans << " ";
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