#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

struct Seg {
    int l, r;
    ll val, tag;
} seg[N << 2];

void push_up(Seg& u, const Seg& l, const Seg& r) {
    u.val = max(l.val, r.val);
}

void push_down(Seg& u, Seg& l, Seg& r) {
    l.val += u.tag;
    l.tag += u.tag;
    r.val += u.tag;
    r.tag += u.tag;
    u.tag = 0;
}

void seg_build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    if (l == r) {
        seg[id].val = 0;
        // cin >> seg[id].val;
        return;
    }
    int m = l + r >> 1;
    seg_build(id << 1, l, m);
    seg_build(id << 1 | 1, m + 1, r);
    push_up(seg[id], seg[id << 1], seg[id << 1 | 1]);
}

void seg_update(int id, int l, int r, ll val) {
    if (l <= seg[id].l && seg[id].r <= r) {
        seg[id].val += val;
        seg[id].tag += val;
        return;
    }
    push_down(seg[id], seg[id << 1], seg[id << 1 | 1]);
    int m = seg[id].l + seg[id].r >> 1;
    if (l <= m)
        seg_update(id << 1, l, r, val);
    if (m < r)
        seg_update(id << 1 | 1, l, r, val);
    push_up(seg[id], seg[id << 1], seg[id << 1 | 1]);
}

void sol() {
    int n, k, A;
    cin >> n >> k >> A;
    ll s = 0;
    vector<vector<pair<int, int>>> p(k + 1);
    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        p[k - y].emplace_back(x, w);
        s += w;
    }
    vector<ll> dp(k + 1);
    seg_build(1, 0, k);
    for (int i = 1; i <= k; i++) {
        seg_update(1, 0, i - 1, -A);
        for (auto [x, w] : p[i])
            seg_update(1, 0, x, w);
        dp[i] = max(dp[i - 1], seg[1].val);
        seg_update(1, i, i, dp[i]);
    }
    cout << s - dp[k] << "\n";
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