#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define ls (id<<1)
#define rs (id<<1|1)

int a[N];

struct Seg {
    int l, r;
    int val;
} seg[N<<2];

void push_up(int id) {
    seg[id].val = seg[ls].val + seg[rs].val;
}

void seg_build(int id, int l, int r) {
    seg[id].l = l; seg[id].r = r; 
    if (l == r) {
        seg[id].val = a[l];
        return ;
    }
    int m = l+r>>1;
    seg_build(ls, l, m);
    seg_build(rs, m+1, r);
    push_up(id);
}

void seg_update(int id, int l, int r) {
    if (seg[id].l == seg[id].r) {
        seg[id].val = 1-seg[id].val;
        return ;
    }
    int m = seg[id].l + seg[id].r >> 1;
    if (l <= m) seg_update(ls, l, r);
    if (m < r) seg_update(rs, l, r);
    push_up(id);
}

int seg_query(int id, int l, int r) {
    if (l <= seg[id].l && seg[id].r <= r) {
        return seg[id].val;
    }
    int m = seg[id].l + seg[id].r >> 1, rt = 0;
    if (l <= m) rt += seg_query(ls, l, r);
    if (m < r) rt += seg_query(rs, l, r);
    return rt;
}

void seg_print() {
	for (int i=1; i<(N<<2); i++) {
		if (seg[i].l != 0)
		cout << "id:" << i << " [" << seg[i].l << "," << seg[i].r << "] val:" << seg[i].val << endl;
	}
}
int main() {
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;
    a[1] = 0;
    for (int i=1; i<n; i++) {
        if (s[i] == s[i-1]) a[i+1] = 0;
        else a[i+1] = 1;
    }
    seg_build(1, 1, n);
    seg_print();
    for (int i=0; i<q; i++) {
    	// cout << i << endl;
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 2) {
            seg_update(1, l, l);
            if (r<n) seg_update(1, r+1, r+1);
        } else {
            cout << seg_query(1, l+1, r) << endl;
        }
    }
    return 0;
}