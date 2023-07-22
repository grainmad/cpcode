#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k, vector<int>(1, -1));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        a[x].push_back(i);
    }
    for (int i = 0; i < k; i++)
        a[i].push_back(n);
    int ans = n;
    for (int i = 0; i < k; i++) {
        int mx = 0, smx = 0;
        for (int j = 1; j < a[i].size(); j++) {
            int d = a[i][j] - a[i][j - 1] - 1;
            if (d > mx) {
                smx = mx;
                mx = d;
            } else if (d > smx) {
                smx = d;
            }
        }
        ans = min(max(mx / 2, smx), ans);
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