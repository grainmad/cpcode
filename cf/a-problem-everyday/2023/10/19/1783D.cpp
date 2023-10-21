
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 100005
#define MOD 998244353
using namespace std;

int f[301][2*N];

void sol() {
	int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i:a) cin >> i;
    f[1][a[1]+N] = 1;
    for (int i=1; i+1<n; i++) {
        for (int j=-90000; j<=90000; j++) {
            if(f[i][j+N]) {
                f[i+1][a[i+1]-j+N] += f[i][j+N];
                f[i+1][a[i+1]-j+N] %= MOD;
                if (j!=0) {
                    f[i+1][a[i+1]+j+N] += f[i][j+N];
                    f[i+1][a[i+1]+j+N] %= MOD;
                }
            }
        }
    }
    ll ans = 0;
    for (int i=-90000; i<=90000; i++) {
        ans += f[n-1][i+N];
        ans %= MOD;
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
