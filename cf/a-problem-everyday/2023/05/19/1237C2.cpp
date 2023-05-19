
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
#define D 3
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(D));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }
    auto dfs = [&](auto& self, vector<int> idx, int d) {
        if (d == D) {
            return idx[0];
        }
        map<int, vector<int>> mp;
        for (int i : idx) {
            mp[a[i][d]].push_back(i);
        }
        int cnt = 0;
        vector<int> p;
        for (auto& i : mp) {
            int rt = self(self, i.second, d + 1);
            if (rt != -1) {
                p.push_back(rt);
            }
        }
        for (int i = 1; i < p.size(); i += 2) {
            cout << p[i - 1] + 1 << " " << p[i] + 1 << "\n";
        }
        return p.size() % 2 ? p.back() : -1;
    };
    vector<int> idx(n, 0);
    iota(idx.begin(), idx.end(), 0);
    dfs(dfs, idx, 0);
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
