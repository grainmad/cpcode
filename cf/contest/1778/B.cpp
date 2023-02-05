#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

int mp[N], a[N];

void sol() {
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 0; i <= n; i++) {
        mp[i] = a[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < m; i++) {
        if (mp[a[i - 1]] >= mp[a[i]] || mp[a[i]] > mp[a[i - 1]] + d) {
            cout << "0\n";
            return;
        }
    }
    int ans = N;
    for (int i = 1; i < m; i++) {
        ans = min(ans, mp[a[i]] - mp[a[i - 1]]);
        if (mp[a[i - 1]] + n - 1 - mp[a[i]] >=
            mp[a[i - 1]] + d - mp[a[i]] + 1) {
            ans = min(ans, mp[a[i - 1]] + d - mp[a[i]] + 1);
        }
    }
    cout << ans << "\n";
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