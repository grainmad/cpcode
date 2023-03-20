#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    int q;
    cin >> s >> q;
    int n = s.size();
    vector<vector<int>> p(26, vector<int>(n + 1));
    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i][j - 1] + (s[j - 1] == i + 'a');
        }
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        vector<int> c(26);
        for (int i = 0; i < 26; i++) {
            c[i] = p[i][y] - p[i][x - 1];
        }
        // for (int i : c)
        //     cout << i << " ";
        // cout << endl;
        cout << ((x == y || s[x - 1] != s[y - 1] ||
                  count(c.begin(), c.end(), 0) <= 23)
                     ? "YES"
                     : "NO")
             << "\n";
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