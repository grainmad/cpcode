#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll& i : a)
        cin >> i;
    sort(a.begin(), a.end());

    while (q--) {
        int k;
        cin >> k;
        if (k <= n) {
            ll mn = 1e10 + 7;
            for (int i = 0; i < n; i++) {
                if (i < k)
                    mn = min(mn, a[i] + k - i);
                else
                    mn = min(mn, a[i]);
            }
            cout << mn << " ";
        } else {
            vector<ll> b(a.begin(), a.end());
            for (int i = 0; i < n - 1; i++) {
                b[i] += k--;
            }
            if (k % 2) {
                b[n - 1] += k--;
            }
            ll mn = *min_element(b.begin(), b.end());
            ll m = 0;
            for (ll i : b) {
                m += i - mn;
            }
            if (m < k / 2) {
                mn -= (k / 2 - m + n - 1) / n;
            }
            cout << mn << " ";
        }
    }
    cout << "\n";
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