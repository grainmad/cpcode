#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> fr(n + 1, 0);
    vector<vector<int>> day(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            day[i].push_back(x);
        }
    }
    vector<int> idx(m), ans(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),
         [&](int a, int b) { return day[a].size() < day[b].size(); });
    for (int i : idx) {
        sort(day[i].begin(), day[i].end(),
             [&](int a, int b) { return fr[a] < fr[b]; });
        ans[i] = day[i][0];
        fr[day[i][0]]++;
    }
    int ok = 1;
    for (int i = 1; i <= n; i++) {
        if (fr[i] > (m + 1) / 2)
            ok = 0;
    }
    if (ok) {
        cout << "YES\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        cout << "NO\n";
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