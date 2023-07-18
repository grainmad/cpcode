#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000006
#define MOD 998244353
using namespace std;

int bsz;
int feq[N], cnt[N], v[N], ans[N];
int mxf = 0;
struct Node {
    int l, r, id;
    bool operator<(Node& o) {
        return l / bsz == o.l / bsz ? r < o.r : l / bsz < o.l / bsz;
    }
} a[N];

void add(int x) {
    cnt[feq[v[x]]]--;
    feq[v[x]]++;
    cnt[feq[v[x]]]++;
    mxf = max(mxf, feq[v[x]]);
}

void sub(int x) {
    cnt[feq[v[x]]]--;
    feq[v[x]]--;
    cnt[feq[v[x]]]++;
    if (mxf == feq[v[x]] + 1 && cnt[feq[v[x]] + 1] == 0)
        mxf = feq[v[x]];
}

void sol() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    bsz = sqrt(n);
    sort(a, a + q);
    int l = 1, r = 0;
    for (int i = 0; i < q; i++) {
        while (a[i].l < l)
            add(--l);
        while (a[i].r > r)
            add(++r);
        while (a[i].l > l)
            sub(l++);
        while (a[i].r < r)
            sub(r--);
        ans[a[i].id] = max(1, 2 * mxf - (r - l + 1));
        // cout << mxf << "\n";
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

void sol2() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int feq = 0;
        for (int i = 0; i < 40; i++) {
            int sl = a[uniform_int_distribution<int>(l, r)(rng)];
            int x = lower_bound(g[sl].begin(), g[sl].end(), l) - g[sl].begin();
            int y = upper_bound(g[sl].begin(), g[sl].end(), r) - g[sl].begin();
            feq = max(feq, y - x);
        }
        cout << max(1, 2 * feq - (r - l + 1)) << "\n";
    }
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
    // sol2();
#endif
    return 0;
}