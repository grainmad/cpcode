#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == -1) {
            l++;
        } else if (x == -2) {
            r++;
        } else {
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int asz = a.size();
    int ans = min(max(l, r) + asz, m);
    // cout << ans << "\n";
    for (int i = 0; i < asz; i++) {
        int lcnt = a[i] - 1;
        int rcnt = m - a[i];
        // cout << lcnt << " " << rcnt << " \n";
        // cout << a[i] << "--";
        ans = max(ans, min(lcnt - i, l) + min(rcnt - (asz - i - 1), r) + asz);
    }
    // cout << "\n";
    cout << ans << "\n";
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