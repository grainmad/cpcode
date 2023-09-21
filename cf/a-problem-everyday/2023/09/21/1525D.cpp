#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;


void sol() {
    int n;
    cin >> n;
    vector<int> p, q;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (x) p.push_back(i);
        else q.push_back(i);
    }
    int psz= p.size(), qsz = q.size();
    vector<vector<int>> f(psz, vector<int>(qsz, -1));
    // f[i][j] = min(f[i][j-1], f[i-1][j-1]+abs(p[i]-q[j]));
    auto dfs = [&](auto self, int i, int j) {
        if (i < 0) return 0;
        if (j < 0) return INF;
        if (f[i][j] != -1) return f[i][j];
        f[i][j] = INF;
        return f[i][j] = min(self(self, i, j-1), self(self, i-1, j-1) + abs(p[i]-q[j]));
    };
    cout << dfs(dfs, psz-1, qsz-1) << "\n";
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