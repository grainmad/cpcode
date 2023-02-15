#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N], p[N];

void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        a[i] = p[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        p[i] += p[i - 1];
    }
    int s = 0, e = n;
    for (int l = 0, r = 1; r <= n; r++) {
        while (2 * (p[r] - p[l]) - n >= k) {
            l++;
            if (r - l < e - s) {
                s = l;
                e = r;
            }
        }
    }
    cout << s << " " << e << "\n";
    ll pos = 0, cnt = 0;
    for (int i = 1, c = 0; i <= n; i++) {
        if (c == k - 1) {
            break;
        }
        cnt += (s <= a[i] && a[i] <= e ? 1 : -1);
        if (cnt == 1) {
            cout << pos + 1 << " " << i << "\n";
            pos = i;
            cnt = 0;
            c++;
        }
    }
    cout << pos + 1 << " " << n << "\n";
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