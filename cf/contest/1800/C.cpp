#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    priority_queue<ll> q;
    int n;
    ll ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x) {
            q.push(x);
        } else if (q.size()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << endl;
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