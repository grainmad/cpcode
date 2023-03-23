#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, l, k;
    cin >> n >> l >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> g(n, string(l, ' '));
    int p = 0, l0 = 0;
    for (int i = 0; i < l; i++) {
        int l = l0;
        for (int j = l0; j < k; j++) {
            g[j][i] = s[p++];
            if (g[j][i] != g[l][i])
                l = j;
        }
        l0 = l;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            if (g[i][j] == ' ')
                g[i][j] = s[p++];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << g[i] << "\n";
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