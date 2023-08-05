
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 100005
#define MOD 998244353
using namespace std;

int st[N];

int ufind(int x) {
    return st[x] < 0 ? x : st[x] = ufind(st[x]);
}

struct Node {
    int u, v, w;
    bool operator<(const Node& o) const { return w < o.w; }
};

void sol() {
    memset(st, -1, sizeof(st));
    int n, m;
    cin >> n >> m;
    vector<Node> a(m);
    for (auto& i : a) {
        cin >> i.u >> i.v >> i.w;
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i < m; i++) {
        int x = ufind(a[i].u), y = ufind(a[i].v);
        if (x != y) {
            int p = ufind(a[0].u), q = ufind(a[0].v);
            if (x == p && y == q || x == q && y == p) {
                cout << a[i].w << "\n";
                return;
            }
            st[x] = y;
        }
    }
    cout << "1000000000\n";
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
