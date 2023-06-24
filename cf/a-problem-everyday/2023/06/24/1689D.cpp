
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353

using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto& i : g)
        cin >> i;
    int mxlu = -N, mnlu = N, mxru = -N, mnru = N;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'B') {
                mxlu = max(mxlu, i - j);
                mnlu = min(mnlu, i - j);
                mxru = max(mxru, i + j);
                mnru = min(mnru, i + j);
            }
        }
    }
    int ans = N, x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = max({abs(i - mnlu - j), abs(i - mxlu - j),
                          abs(mnru - i - j), abs(mxru - i - j)});
            if (ans > mx) {
                ans = mx;
                x = i;
                y = j;
            }
        }
    }
    cout << x + 1 << " " << y + 1 << endl;
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
