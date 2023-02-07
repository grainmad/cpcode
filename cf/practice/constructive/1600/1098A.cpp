#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;

vector<int> g[N];
ll s[N];

bool fs(int u, int fa) {
    if (s[u] == -1) {
        ll mn = INF;
        for (int i : g[u]) {
            mn = min(mn, s[i]);
        }
        s[u] = mn == INF ? s[fa] : mn;
    }
    if (s[u] < s[fa])
        return false;
    for (int i : g[u]) {
        if (!fs(i, u))
            return false;
    }
    return true;
}

ll cnt(int u, int fa) {
    ll rt = s[u] - s[fa];
    for (int i : g[u]) {
        rt += cnt(i, u);
    }
    return rt;
}

void sol() {
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    if (!fs(1, 0)) {
        cout << "-1\n";
    } else {
        cout << cnt(1, 0) << "\n";
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