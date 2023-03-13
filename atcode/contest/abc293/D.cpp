#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define B 200005
#define MOD 998244353
using namespace std;

int st[N];
void uf_init() {
    memset(st, -1, sizeof(st));
}
int uf_find(int x) {
    return st[x] < 0 ? x : st[x] = uf_find(st[x]);
}
void uf_union(int x, int y) {
    int fx = uf_find(x), fy = uf_find(y);
    if (fx != fy) {
        st[fx] += st[fy];
        st[fy] = fx;
    }
}

int getval() {
    int x;
    string s;
    cin >> x >> s;
    return x + (s == "B" ? B : 0);
}

void sol() {
    uf_init();
    int n, m, cy = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        uf_union(i, i + B);
    }
    for (int i = 0; i < m; i++) {
        int a = getval();
        int b = getval();
        int fa = uf_find(a), fb = uf_find(b);
        if (fa == fb)
            cy++;
        else {
            uf_union(a, b);
        }
    }
    int g = 0;
    for (int i = 1; i <= n; i++) {
        if (st[i] < 0)
            g++;
        if (st[i + B] < 0)
            g++;
    }
    cout << cy << " " << g - cy << endl;
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