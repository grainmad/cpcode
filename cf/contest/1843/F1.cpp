#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int w[N];
int mx[N], mn[N], pmx[N], pmn[N];
int fa[N];

void sol() {
    int n;
    cin >> n;
    w[1] = mx[1] = mn[1] = pmx[1] = pmn[1] = 1;
    int cur = 2;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "+") {
            int v, x;
            cin >> v >> x;
            fa[cur] = v;
            w[cur] = x;
            mx[cur] = max(mx[v], 0) + w[cur];
            pmx[cur] = max(mx[cur], pmx[v]);
            mn[cur] = min(mn[v], 0) + w[cur];
            pmn[cur] = min(mn[cur], pmn[v]);
            cur++;
        } else {
            int u, v, k;
            cin >> u >> v >> k;
            if (k == 0 || pmn[v] <= k && k <= pmx[v]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
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