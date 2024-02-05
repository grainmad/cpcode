#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

struct Seg{
	int l, r;
	ll val;
} seg[N<<2];

void push_up(Seg& u, const Seg& l, const Seg& r) {
	u.val = max(l.val, r.val);
}


void seg_build(int id, int l, int r) {
	seg[id].l = l; seg[id].r = r;
	if (l == r) {
		seg[id].val = 0;
		// cin >> seg[id].val;
		return ;
	}
	int m = l+r>>1;
	seg_build(id<<1, l, m);
	seg_build(id<<1|1, m+1, r);
	push_up(seg[id], seg[id<<1], seg[id<<1|1]);
}

void seg_update(int id, int l, int r, ll val) {
	if (l <= seg[id].l && seg[id].r <= r) {
		seg[id].val = val;
		return ;
	}
	int m = seg[id].l + seg[id].r >> 1;
	if (l <= m) seg_update(id<<1, l, r, val);
	if (m < r) seg_update(id<<1|1, l, r, val);
	push_up(seg[id], seg[id<<1], seg[id<<1|1]);
}

ll seg_query(int id, int l, int r) {
	if (l <= seg[id].l && seg[id].r <= r) {
		return seg[id].val;
	}
	ll rt = 0;
	int m = seg[id].l + seg[id].r >> 1;
	if (l <= m) rt = max(rt, seg_query(id<<1, l, r));
	if (m < r) rt = max(rt, seg_query(id<<1|1, l, r));
	return rt;
}

void sol() {
    int n, d;
    cin >> n >> d;
    int E = 500002;
    seg_build(1, 1, E);
    ll ans = 0;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        ll v = seg_query(1, max(1, x-d), min(x+d, E))+1;
        // cout << i << " " << v << endl;
        ans = max(ans, v);
        seg_update(1, x, x, v);
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