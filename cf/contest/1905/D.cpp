#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 1000005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> p(n), a(n + 1), ap(n + 1);
    int mex = 0;
    ll sum = 0;
    deque<pair<ll, ll>> dq;
    for (auto& i : p) {
        cin >> i;
        ap[i] = 1;
        while (ap[mex])
            mex++;
        dq.emplace_back(mex, 1);
        // cout << mex << " ";
        sum += mex;
    }
    ll ans = sum;
    for (int i = 0; i < n; i++) {
        pair<ll, ll> c = {p[i], 0};
        sum -= dq.front().first;
        if (--dq.front().second == 0) {
            dq.pop_front();
        }
        while (dq.size() && dq.back().first >= p[i]) {
            sum -= dq.back().first * dq.back().second;
            c.second += dq.back().second;
            dq.pop_back();
        }
        dq.emplace_back(c);
        sum += c.first * c.second;
        dq.emplace_back(n, 1);
        sum += n;
        ans = max(ans, sum);
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