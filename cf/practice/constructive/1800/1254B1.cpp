#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x)
            a.push_back(i);
    }
    int sz = a.size();
    ll ans = 1e12;
    auto temp = [&](int itv) {
        ll cur = 0;
        for (int j = 0; j < sz; j += itv) {
            int l = j, r = j + itv - 1;
            while (l < r) {
                cur += a[r--] - a[l++];
            }
        }
        return cur;
    };
    for (int i = 1; i * i <= sz; i++) {
        if (sz % i)
            continue;

        if (i > 1)
            ans = min(ans, temp(i));
        if (sz / i != i)
            ans = min(ans, temp(sz / i));
    }
    cout << (ans == 1e12 ? -1 : ans) << "\n";
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