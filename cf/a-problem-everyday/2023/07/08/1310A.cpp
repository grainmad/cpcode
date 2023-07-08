
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
    vector<pair<ll, ll>> a(n);
    for (auto& [i, j] : a)
        cin >> i;
    for (auto& [i, j] : a)
        cin >> j;
    sort(a.begin(), a.end());
    // for (auto& [i, j] : a) {
    //     cout << i << " " << j << endl;
    // }
    priority_queue<ll> q;
    ll p = 0, s = 0, ans = 0;
    for (auto [i, j] : a) {
        for (ll k = p; k < i && q.size(); k++) {
            s -= q.top();
            q.pop();
            ans += s;
        }
        s += j;
        q.push(j);
        p = i;
    }
    while (q.size()) {
        s -= q.top();
        q.pop();
        ans += s;
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
