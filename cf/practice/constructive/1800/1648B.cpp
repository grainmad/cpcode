#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 1000005
#define MOD 998244353
using namespace std;

ll cnt[N], ps[N];

void sol() {
    ll n, c;
    cin >> n >> c;
    for (int i = 0; i <= c; i++)
        cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x] = 1;
    }
    for (int i = 1; i <= c + 1; i++) {
        ps[i] = ps[i - 1] + cnt[i - 1];
    }
    vector<ll> p, q;
    for (int i = 1; i <= c; i++) {
        if (cnt[i])
            q.push_back(i);
        else
            p.push_back(i);
    }
    for (ll y : q) {
        for (ll r : p) {
            if (y * r > c)
                break;
            if (ps[min(y * r + y, c + 1)] != ps[y * r]) {
                cout << "NO\n";
                return;
            }
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