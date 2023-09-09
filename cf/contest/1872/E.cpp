#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

string s;

ll a[N];

struct Seg {
    int l, r;
    ll sum, val, tag;
} seg[N << 2];

void push_up(Seg& u, const Seg& l, const Seg& r) {
    u.val = l.val ^ r.val;
    u.sum = l.sum ^ r.sum;
}

void push_down(Seg& u, Seg& l, Seg& r) {
    if (u.tag) {
        l.val = l.sum ^ l.val;
        l.tag ^= u.tag;
        r.val = r.sum ^ r.val;
        r.tag ^= u.tag;
    }
    u.tag = 0;
}

void seg_build(int id, int l, int r) {
    seg[id].l = l;
    seg[id].r = r;
    seg[id].val = 0;
    seg[id].sum = 0;
    seg[id].tag = 0;
    if (l == r) {
        seg[id].val = s[l] == '1' ? a[l] : 0;
        seg[id].sum = a[l];
        // cin >> seg[id].val;
        return;
    }
    int m = l + r >> 1;
    seg_build(id << 1, l, m);
    seg_build(id << 1 | 1, m + 1, r);
    push_up(seg[id], seg[id << 1], seg[id << 1 | 1]);
}

void seg_update(int id, int l, int r) {
    if (l <= seg[id].l && seg[id].r <= r) {
        seg[id].val = seg[id].sum ^ seg[id].val;
        seg[id].tag ^= 1;
        return;
    }
    push_down(seg[id], seg[id << 1], seg[id << 1 | 1]);
    int m = seg[id].l + seg[id].r >> 1;
    if (l <= m)
        seg_update(id << 1, l, r);
    if (m < r)
        seg_update(id << 1 | 1, l, r);
    push_up(seg[id], seg[id << 1], seg[id << 1 | 1]);
}

ll seg_query(int id, int l, int r) {
    if (l <= seg[id].l && seg[id].r <= r) {
        return seg[id].val;
    }
    push_down(seg[id], seg[id << 1], seg[id << 1 | 1]);
    ll rt = 0;
    int m = seg[id].l + seg[id].r >> 1;
    if (l <= m)
        rt ^= seg_query(id << 1, l, r);
    if (m < r)
        rt ^= seg_query(id << 1 | 1, l, r);
    return rt;
}

void sol() {
    int n;
    cin >> n;
    ll xr = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        xr ^= a[i];
    }
    cin >> s;
    s = "+" + s;
    seg_build(1, 1, n);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            int x, y;
            cin >> x >> y;
            seg_update(1, x, y);
        } else {
            int g;
            cin >> g;
            ll t = seg_query(1, 1, n);
            if (g)
                cout << t << " ";
            else
                cout << (xr ^ t) << " ";
        }
    }
    cout << "\n";
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