
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    vector c(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++)
            c[i][j] = c[i - 1][j];
        c[i][s[i - 1] - 'a']++;
    }
    auto check = [&](int l, int r) {
        int d = 0;
        for (int i = 0; i < 26; i++) {
            d += c[r][i] != c[l - 1][i];
        }
        return d >= 3;
    };
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r || s[l - 1] != s[r - 1] || check(l, r)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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
