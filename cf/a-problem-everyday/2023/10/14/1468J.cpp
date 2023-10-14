
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

struct Seg {
    int u, v, s;
    Seg(int u, int v, int s):u(u), v(v), s(s) {}
    bool operator<(const Seg& o) const {
        return s < o.s;
    }
};



void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> st(n, -1);
    function<int(int)> ufind = [&](int x) {
        return st[x] < 0 ? x : st[x] = ufind(st[x]);
    };
    vector<Seg> seg;
    for (int i=0; i<m; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        x--; y--;
        seg.emplace_back(x, y, s);
    }
    sort(seg.begin(), seg.end());
    ll mx = -1;
    for (int i=m-1; i>=0; i--) {
        if (seg[i].s <= k) {
            mx = max(1LL*seg[i].s , mx);
            int x = ufind(seg[i].u);
            int y = ufind(seg[i].v);
            if (x != y) {
                st[x] += st[y];
                st[y] = x;
            }
        }
    }

    

    if (-st[ufind(1)] != n) { // 小于等于k的边无法构成生成树。加边直到构成生成树。
        ll cnt = 0;
        for (int i=0; i<m; i++) {
            if (seg[i].s > k) {
                int x = ufind(seg[i].u);
                int y = ufind(seg[i].v);
                if (x != y) {
                    st[x] += st[y];
                    st[y] = x;
                    cnt += seg[i].s-k; // 所有大于k的边变为k，需操作次数
                }
                if (-st[ufind(1)] == n) { // 连通
                    break;
                }
            }
        }
        cout << cnt << "\n";
    } else { // 可以构成生成树，则k-mx为贡献，此外考虑替换一条边为 最小大于k的边
        ll cnt = 0x3f3f3f3f;
        for (int i=0; i<m; i++) {
            if (seg[i].s > k) {
                cnt = seg[i].s-k;
                break;
            }
        }
        cout << min(cnt, k-mx) << "\n";
    }

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
