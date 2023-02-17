#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

ll a[N], b[N], d[N], o[N], ans[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        a[i] = b[i] = d[i] = o[i] = ans[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int p = lower_bound(b, b + n + 1, a[i] + b[i - 1]) - b;
        d[i]++;
        d[p]--;
        o[p] += a[i] - b[p - 1] + b[i - 1];
        // cout << i << " " << p << " " << b[p - 1] - b[i - 1] << " op: " <<
        // o[p]
        //      << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << d[i] << " ";
    // }
    // cout << " d\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << o[i] << " ";
    // }
    // cout << " o\n";
    ll pre = 0;
    for (int i = 1; i <= n; i++) {
        pre += d[i];
        cout << pre * (b[i] - b[i - 1]) + o[i] << " ";
    }
    cout << "\n";
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