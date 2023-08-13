#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

struct Node {
    int x, t, p;
    bool operator<(const Node& o) const { return x < o.x; }
    Node(int x, int t, int p) : x(x), t(t), p(p) {}
};

void sol() {
    int n;
    cin >> n;
    vector<Node> v;
    vector<int> mx;
    for (int i = 0; i < n; i++) {
        int l, a, b, r;
        cin >> l >> a >> b >> r;
        mx.push_back(b);
        v.emplace_back(l, 0, i);
        v.emplace_back(a, 1, i);
        v.emplace_back(b, 1, i);
        v.emplace_back(r, 0, i);
    }
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    vector<int> pos(q), idx(q);
    for (auto& i : pos)
        cin >> i;
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) { return pos[x] < pos[y]; });
    vector<int> ans(q);
    int p = 0;
    int r = 0;
    for (auto& o : v) {
        r = max(r, mx[o.p]);
        while (p < q && pos[idx[p]] < o.x)
            ans[idx[p++]] = max(r, o.x);
    }
    for (int i : ans) {
        cout << i << " ";
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