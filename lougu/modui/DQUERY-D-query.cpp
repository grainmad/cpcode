#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000006
#define MOD 998244353
using namespace std;

int bsz;
int cnt[N], v[N], ans[N];
int cur = 0;
struct Node {
    int l, r, id;
    bool operator<(Node& o) {
        return l / bsz == o.l / bsz ? r < o.r : l / bsz < o.l / bsz;
    }
} a[N];

void add(int x) {
    if (++cnt[v[x]] == 1)
        cur++;
}

void sub(int x) {
    if (--cnt[v[x]] == 0)
        cur--;
}

void sol() {
    int n, q;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    bsz = sqrt(n);
    sort(a, a + q);
    int l = 1, r = 0;
    for (int i = 0; i < q; i++) {
        while (a[i].l < l)
            add(--l);
        while (a[i].r > r)
            add(++r);
        while (a[i].l > l)
            sub(l++);
        while (a[i].r < r)
            sub(r--);
        ans[a[i].id] = cur;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
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