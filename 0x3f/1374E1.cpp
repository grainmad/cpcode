#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int m[N], a[N], b[N], idx[N];

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> l, c, r;
    for (int i = 0; i < n; i++) {
        cin >> m[i] >> a[i] >> b[i];
        if (a[i] && b[i]) {
            c.push_back(m[i]);
        } else if (a[i]) {
            l.push_back(m[i]);
        } else if (b[i]) {
            r.push_back(m[i]);
        }
    }
    if (count(a, a + n, 1) < k || count(b, b + n, 1) < k) {
        cout << "-1\n";
        return;
    }
    sort(l.begin(), l.end());
    sort(c.begin(), c.end());
    sort(r.begin(), r.end());

    vector<int> p(min(l.size(), r.size()) + 1);
    int psz = p.size();
    for (int i = 1; i < psz; i++) {
        p[i] = p[i - 1] + l[i - 1] + r[i - 1];
    }
    vector<int> q(c.size() + 1);
    int qsz = q.size();
    for (int i = 1; i < qsz; i++) {
        q[i] = q[i - 1] + c[i - 1];
    }
    ll ans = 1e15;
    for (int i = min(k, psz - 1); i >= 0 && k - i < qsz; i--) {
        ans = min(ans, 0LL + q[k - i] + p[i]);
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