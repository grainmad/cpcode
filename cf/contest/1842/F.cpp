#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 5005
#define MOD 998244353
using namespace std;

vector<int> g[N];

void sol() {
    ll n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll c[N];
    memset(c, 0x3f, sizeof(c));
    c[0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<ll> deep(n + 1, -1);
        deep[i] = 0;
        queue<int> q;
        q.push(i);
        ll s = 0;
        for (int j = 1; j <= n; j++) {
            int u = q.front();
            q.pop();
            s += deep[u] * 2;
            c[j] = min(c[j], s);
            for (int v : g[u]) {
                if (deep[v] == -1) {
                    deep[v] = deep[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << i * (n - 1) - c[i] << " ";
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