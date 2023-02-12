#include <bits/stdc++.h>
// #define SINGPE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

ll a[N], l[N], r[N], pre[N], suf[N];

struct ST {
    struct Seg {
        int l, r;
        ll val;
    } seg[N << 2];

    void push_up(Seg& u, const Seg& l, const Seg& r) {
        u.val = max(l.val, r.val);
    }

    void seg_build(int id, int l, int r, ll* v) {
        seg[id].l = l;
        seg[id].r = r;
        if (l == r) {
            seg[id].val = v[l];
            return;
        }
        int m = l + r >> 1;
        seg_build(id << 1, l, m, v);
        seg_build(id << 1 | 1, m + 1, r, v);
        push_up(seg[id], seg[id << 1], seg[id << 1 | 1]);
    }

    ll seg_query(int id, int l, int r) {
        if (l <= seg[id].l && seg[id].r <= r) {
            return seg[id].val;
        }
        ll rt = -1e15;
        int m = seg[id].l + seg[id].r >> 1;
        if (l <= m)
            rt = max(rt, seg_query(id << 1, l, r));
        if (m < r)
            rt = max(rt, seg_query(id << 1 | 1, l, r));
        return rt;
    }
} P, S;

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l[i] = 0;
        r[i] = n + 1;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    P.seg_build(1, 1, n, pre);
    S.seg_build(1, 1, n, suf);
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (st.size() && a[st.back()] < a[i]) {
            r[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while (st.size())
        st.pop_back();

    for (int i = 1; i <= n; i++) {
        while (st.size() && a[st.back()] <= a[i]) {
            st.pop_back();
        }
        if (st.size())
            l[i] = st.back();
        st.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        int x = l[i] + 1, y = r[i] - 1;
        if (P.seg_query(1, i, y) - pre[i] + S.seg_query(1, x, i) - suf[i] > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGPE_INPUT
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