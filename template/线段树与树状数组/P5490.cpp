//扫描线求面积
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ls (id<<1)
#define rs (id<<1|1)
#define N 100005
using namespace std;

struct Line {
	int x1, x2, y, val;
	bool operator<(const Line& o) const {
		return y < o.y;
	}
};
std::vector<Line> line;
std::vector<int> X;

struct Seg {
	int l, r, cnt;
	ll len;
} seg[N<<3];


void seg_build(int id, int l, int r) {
	seg[id] = {l, r, 0, 0};
	if (l == r) return;
	int m = l+r>>1;
	seg_build(ls, l, m);
	seg_build(rs, m+1, r);
}

void push_up(int id) {
	if (seg[id].cnt > 0) {
		seg[id].len = X[seg[id].r+1]-X[seg[id].l];
	} else {
		seg[id].len = seg[ls].len + seg[rs].len;
	}
}

void seg_update(int id, int l, int r, int val) {
	if (r <= X[seg[id].l] || X[seg[id].r+1] <= l) return ;
	if (l <= X[seg[id].l] && X[seg[id].r+1] <= r) {
		seg[id].cnt += val;
		push_up(id);
		return;
	}
	// int m = seg[id].l + seg[id].r >> 1;
	// if (l <= X[m]) 
		seg_update(ls, l, r, val);
	// if (X[m+1] < r) 
		seg_update(rs, l, r, val);
	push_up(id);
}

void seg_print() {
	for (int i=1; i<(N<<2); i++) {
		if (seg[i].r != 0)
		cout << "id:" << i << " [" << X[seg[i].l] << "," << X[seg[i].r] << "] len:" << seg[i].len << " cnt:" << seg[i].cnt << endl;
	}
}


void sol() {
	int n, x1, x2, y1, y2;
	cin >> n;
	set<int> stx;
	for (int i=0; i<n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		line.push_back({x1, x2, y1, 1});
		line.push_back({x1, x2, y2, -1});
		stx.insert(x1); stx.insert(x2);
	}
	X = std::vector<int>(stx.begin(), stx.end());
	sort(line.begin(), line.end());
	// for (auto i:line) {
	// 	cout << i.x1 << " " << i.x2 << " " << i.y << " " << i.val << endl;
	// }
	// for (int i:X) {
	// 	cout << i << " ";
	// } cout << endl;
	seg_build(1, 0, X.size()-2);
	// seg_print();
	// cout << seg[1].l << " " << seg[1].r << endl;
	// cout << X[seg[1].l] << " " << X[seg[1].r] << endl;
	ll ans = 0;
	for (int i=0; i<line.size()-1; i++) {
		seg_update(1, line[i].x1, line[i].x2, line[i].val);
		// cout << seg[1].len << endl;
		ans += seg[1].len*(line[i+1].y-line[i].y);

	}
	cout << ans << endl;
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