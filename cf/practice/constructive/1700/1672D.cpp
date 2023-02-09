#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

ll a[N], b[N];

void sol() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    b[n + 1] = 0;
    int p = n, q = n;
    while (p > 0) {
        if (a[p] == b[q]) {
            p--;
            q--;
        } else if (b[q] == b[q + 1]) {
            cnt[b[q--]]++;
        } else if (cnt[a[p]]) {
            cnt[a[p--]]--;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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