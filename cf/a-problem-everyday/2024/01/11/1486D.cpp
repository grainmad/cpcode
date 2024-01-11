
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n+1;
    while (l<r) {
        int m = l+r>>1;
        vector<int> x(n+1), y(n+1);
        for (int i=1; i<=n; i++) {
            x[i] = x[i-1];
            y[i] = y[i-1];
            if (a[i]<m) x[i]++;
            else y[i]++;
        }
        int mn = 0, ok = 0;
        for (int i=k; i<=n; i++) {
            if (y[i]-x[i]-1>=mn) {
                ok = 1;
                break;
            }
            mn = min(mn, y[i-k+1]-x[i-k+1]);
        }
        if (ok) {
            l = m+1;
        } else {
            r = m;
        }
    }
    cout << r-1 << "\n";
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
