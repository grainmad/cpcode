#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(2 * n);
    for (ll& i : a)
        cin >> i;
    auto get_ans = [&]() {
        ll ans = 0;
        for (ll i : a)
            ans += abs(i);
        if (n % 2) {
            return ans;
        } else {
            ll c = 0, eans = ans;
            for (int i : a)
                c += abs(-1 - i);
            for (int i : a) {
                eans = min(eans, c - abs(-1 - i) + abs(n - i));
            }
            return eans;
        }
    };
    if (n == 1) {
        cout << min(get_ans(), abs(a[0] - a[1])) << "\n";
    } else if (n == 2) {
        ll ans = 0;
        for (ll i : a)
            ans += abs(i - 2);
        cout << min(get_ans(), ans) << "\n";
    } else {
        cout << get_ans() << "\n";
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