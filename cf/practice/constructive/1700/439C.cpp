#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, k, p;
    vector<ll> a, b;
    cin >> n >> k >> p;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x % 2)
            a.push_back(x);
        else
            b.push_back(x);
    }
    if (a.size() >= k - p && (a.size() - k + p) % 2 == 0 &&
        (a.size() - k + p) / 2 + b.size() >= p) {
        cout << "YES\n";
        for (int i = 0; i < (p == k ? p - 1 : p); i++) {
            if (b.size()) {
                cout << "1 " << b.back() << "\n";
                b.pop_back();
            } else {
                cout << "2 " << a.back();
                a.pop_back();
                cout << " " << a.back();
                a.pop_back();
                cout << "\n";
            }
        }
        for (int i = 0; i < k - p - 1; i++) {
            cout << "1 " << a.back() << "\n";
            a.pop_back();
        }
        if (a.size() || b.size()) {
            cout << a.size() + b.size();
            while (a.size()) {
                cout << " " << a.back();
                a.pop_back();
            }
            while (b.size()) {
                cout << " " << b.back();
                b.pop_back();
            }
            cout << "\n";
        }

    } else {
        cout << "NO\n";
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