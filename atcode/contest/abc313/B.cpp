#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 55
#define MOD 998244353
using namespace std;

vector<int> g[N];

int in[N];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        in[y]++;
    }
    int ans = -1, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            cnt++;
            ans = i;
        }
    }
    if (cnt == 1)
        cout << ans << "\n";
    else
        cout << "-1\n";
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