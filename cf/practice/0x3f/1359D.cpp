#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

int a[N];

void sol() {
    int n;
    cin >> n;
    int lb = 50, ub = -50;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lb = min(lb, a[i]);
        ub = max(ub, a[i]);
    }
    int ans = 0;
    for (int i = lb; i <= ub; i++) {
        int s = 0, mx = -50;
        for (int x = 0; x < n; x++) {
            if (a[x] > i || s + a[x] <= 0) {
                s = 0, mx = -50;
            } else {
                s += a[x];
                mx = max(mx, a[x]);
                ans = max(ans, s - mx);
            }
        }
    }
    cout << ans << endl;
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