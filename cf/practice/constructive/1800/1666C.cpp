#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    vector<pair<int, int>> d;
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        d.emplace_back(x, y);
    }
    sort(d.begin(), d.end(),
         [](auto& a, auto& b) { return a.first < b.first; });
    int mx = d[1].first;
    cout << "5\n";
    for (auto [i, j] : d) {
        cout << i << " " << j << " " << mx << " " << j << "\n";
    }
    sort(d.begin(), d.end(),
         [](auto& a, auto& b) { return a.second < b.second; });
    for (int i = 1; i < 3; i++) {
        cout << mx << " " << d[i - 1].second << " " << mx << " " << d[i].second
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