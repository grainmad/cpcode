
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (string& i : s)
        cin >> i;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            a[i][j] = a[i + 1][j] + a[i][j + 1] - a[i + 1][j + 1];
            if (s[i][j] == 'W') {
                if (a[i][j] != 1)
                    a[i][j] = 1, ans++;
            } else {
                if (a[i][j] != -1)
                    a[i][j] = -1, ans++;
            }
        }
    }
    cout << ans << "\n";
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
