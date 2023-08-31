
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

int ch[200];

void sol() {
    ch['w'] = 0;
    ch['i'] = 1;
    ch['n'] = 2;
    int m;
    cin >> m;
    map<string, vector<int>> mp;
    vector<int> c(3);
    vector<int> g[3][3];
    for (int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        c[0] = c[1] = c[2] = 0;
        for (char j : s)
            c[ch[j]]++;
        if (c[0] == 3) {
            g[0][1].push_back(i);
            g[0][2].push_back(i);
        }
        if (c[1] == 3) {
            g[1][0].push_back(i);
            g[1][2].push_back(i);
        }
        if (c[2] == 3) {
            g[2][0].push_back(i);
            g[2][1].push_back(i);
        }
        if (c[0] == 2) {
            g[0][c[1] ? 2 : 1].push_back(i);
        }
        if (c[1] == 2) {
            g[1][c[2] ? 0 : 2].push_back(i);
        }
        if (c[2] == 2) {
            g[2][c[1] ? 0 : 1].push_back(i);
        }
    }
    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         cout << g[i][j].size() << " ";
    //     }
    //     cout << endl;
    // }
    vector<string> ans;
    while (g[0][1].size() && g[1][0].size()) {
        ans.push_back(to_string(g[0][1].back()) + " w " +
                      to_string(g[1][0].back()) + " i");
        g[0][1].pop_back();
        g[1][0].pop_back();
    }
    while (g[1][2].size() && g[2][1].size()) {
        ans.push_back(to_string(g[1][2].back()) + " i " +
                      to_string(g[2][1].back()) + " n");
        g[1][2].pop_back();
        g[2][1].pop_back();
    }
    while (g[0][2].size() && g[2][0].size()) {
        ans.push_back(to_string(g[0][2].back()) + " w " +
                      to_string(g[2][0].back()) + " n");
        g[0][2].pop_back();
        g[2][0].pop_back();
    }
    while (g[0][1].size() && g[1][2].size() && g[2][0].size()) {
        ans.push_back(to_string(g[0][1].back()) + " w " +
                      to_string(g[1][2].back()) + " i");
        ans.push_back(to_string(g[1][2].back()) + " w " +
                      to_string(g[2][0].back()) + " n");
        g[0][1].pop_back();
        g[1][2].pop_back();
        g[2][0].pop_back();
    }
    while (g[0][2].size() && g[2][1].size() && g[1][0].size()) {
        ans.push_back(to_string(g[0][2].back()) + " w " +
                      to_string(g[2][1].back()) + " n");
        ans.push_back(to_string(g[2][1].back()) + " w " +
                      to_string(g[1][0].back()) + " i");
        g[0][2].pop_back();
        g[2][1].pop_back();
        g[1][0].pop_back();
    }
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << "\n";
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
