
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    int L, R;
    cin >> L >> R;
    int mn = n + 1;
    vector<ll> suf_sm(n + 1, 0), suf_xr(n + 1, 0);
    ll sm = 0, xr = 0;
    ll mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        sm += a[i];
        xr ^= a[i];
        suf_sm[i] = sm;
        suf_xr[i] = xr;
        mx = max(mx, sm - xr);
    }
    for (int i = 0; i < n; i++) {
        if (mx != sm - xr)
            continue;
        int l = i + 1, r = n;
        while (l < r) {
            int m = l + r >> 1;
            // ll tsm = 0, txr = 0;
            // for (int j = i; j < m; j++) {
            //     tsm += a[j];
            //     txr ^= a[j];
            // }
            ll tsm = sm - suf_sm[m], txr = xr ^ suf_xr[m];
            if (tsm - txr == mx) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (mn > r - i) {
            L = i + 1;
            R = r;
            mn = r - i;
        }
        sm -= a[i];
        xr ^= a[i];
    }
    cout << L << " " << R << endl;
}

void sol2() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1), sm(n + 1), xr(n + 1);
    ll mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sm[i] = sm[i - 1] + a[i];
        xr[i] = xr[i - 1] ^ a[i];
        mx = max(mx, sm[i] - xr[i]);
    }
    int L, R;
    cin >> L >> R;
    for (int i = 1, j = 1; i <= n; i++) {
        j = max(i, j);
        while (j <= n && sm[j] - sm[i - 1] - (xr[j] ^ xr[i - 1]) < mx)
            j++;
        if (j > n)
            break;
        if (j - i < R - L) {
            R = j, L = i;
        }
    }
    cout << L << " " << R << "\n";
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
        // sol();
        sol2();
    }
#else
    sol();
#endif
    return 0;
}
