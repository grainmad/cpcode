
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 200005
#define MOD 998244353
using namespace std;

int a[N], l[N], r[N], h[N];

void sol() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        r[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
        l[a[i]] = i;
    }
    vector<int> sp(1, 0);
    for (int i = 1; i <= n; i++) {
        if (i > sp.back())
            sp.push_back(r[a[i]]);
        sp.back() = max(sp.back(), r[a[i]]);
    }
    // for (int i : sp)
    //     cout << i << " ";
    // cout << endl;
    int ans = 0;
    for (int i = 1; i < sp.size(); i++) {
        int mx = 0;
        for (int j = sp[i - 1] + 1; j <= sp[i]; j++) {
            mx = max(mx, ++h[a[j]]);
        }
        ans += sp[i] - sp[i - 1] - mx;
        for (int j = sp[i - 1] + 1; j <= sp[i]; j++) {
            h[a[j]] = 0;
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
