#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define NINF 0xf3f3f3f3f3f3f3f3
#define MOD 998244353
using namespace std;

ll p[N], f[N], a[N];

ll ask(int x) {
    ll mx = NINF;
    for (int i = x; i; i -= i & -i) {
        mx = max(mx, a[i]);
    }
    return mx;
}

void add(int x, ll val) {
    for (int i = x; i < N; i += i & -i) {
        a[i] = max(a[i], val);
    }
}

void sol() {
    memset(a, 0xf3, sizeof(a));
    int n;
    cin >> n;
    map<ll, int> idx;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        p[i] += p[i - 1];
        idx[p[i]];
    }
    idx[0];
    int sz = 1;
    for (auto& [i, j] : idx)
        j = sz++;
    add(idx[0], 0);  // add(idx[p[0]], f[0]-0);
    for (int i = 1; i <= n; i++) {
        f[i] = max(f[i - 1], ask(idx[p[i]]) + i);
        add(idx[p[i]], f[i] - i);
    }
    cout << f[n] << "\n";
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