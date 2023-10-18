
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
    vector<int> a(n);
    for (auto &i:a) cin >> i;
    int ans = 0;
    for (int b=30; b>=0; b--) {
        for (int i=0; i<n; i++) {
            if (a[i] > b) a[i] = -60;
        }
        vector<int> l(n), r(n);
        l[0] = a[0];
        for (int i=1; i<n; i++) {
            l[i] = max(0, l[i-1]) + a[i];
        }
        r[n-1] = a[n-1];
        for (int i=n-2; i>=0; i--) {
            r[i] = max(0, r[i+1]) + a[i];
        }
        for (int i=0; i<n; i++) {
            if (a[i] == b) {
                ans = max(ans, (i-1>=0?max(0, l[i-1]):0)+(i+1<n?max(0, r[i+1]):0));
            }
        }
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
