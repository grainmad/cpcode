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
    vector<ll> a(n), d(1, 0);
    for (auto& i : a)
        cin >> i;
    if (a[0] != 1) {
        cout << "1\n";
        return;
    }
    for (int i = 1; i < n; i++) {
        d.push_back(a[i] - a[i - 1] - 1 + d.back());
    };
    ll p = 1, c = 0, pos = 1;
    for (int i = 0; i < k; i++) {
        while (pos != n && c + a[pos] - a[pos - 1] - 1 < p) {
            c += a[pos] - a[pos - 1] - 1;
            pos++;
        }
        if (pos == n) {
            p += n;
        } else {
            p = a[pos - 1] + p - c;
        }
    }
    cout << p << endl;
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