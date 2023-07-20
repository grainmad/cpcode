
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    // for (int i : a) {
    //     cout << i << " ";
    // }
    // cout << endl;
    vector<int> cnt(n + 1);
    int mx = 0;
    for (int i = 0; i < n;) {
        int p = i;
        while (p < n && a[p] == a[i])
            p++;
        mx = max(mx, p - i);
        cnt[p - i]++;
        i = p;
    }
    for (int i = mx - 1; i >= 0; i--) {
        cnt[i] += cnt[i + 1];
    }
    ll ans = 0;
    for (ll i = 1; i <= mx; i++) {
        ll c = 0;
        for (int j = i, k = cnt[j]; j <= mx && k; j *= 2, k--) {
            c += j;
            if (cnt[j] == 1)
                break;
        }
        ans = max(ans, c);
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
