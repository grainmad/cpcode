#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto& [i, j] : a) {
        cin >> i >> j;
        j += i;
    }

    sort(a.begin(), a.end());
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> q;
    int ans = 0;
    int p = 0;

    for (ll i = 0;; i++) {
        while (q.size() && q.top().first < i) {
            q.pop();
        }
        if (q.empty()) {
            if (p == n)
                break;
            i = a[p].first;
        }
        while (p < n && i == a[p].first) {
            q.emplace(a[p].second, a[p].first);
            p++;
        }
        q.pop();
        ans++;
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