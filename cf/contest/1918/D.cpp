#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n;
    cin >> n;
    vector<ll> a(n+1), p(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        p[i] = p[i-1] + a[i];
    }
    ll l = 0, r = 1e15;
    while (l<r) {
        ll m = l+r>>1;
        // cout << m << ":\n";
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        pq.emplace(0,0);
        vector<ll> dp(n+1);
        int ok = 0;
        int x = 0;
        for (int i=1; i<=n; i++) {
            while (p[i-1]-p[x]>m) x++;
            while (pq.top().second < x) pq.pop();
            dp[i] = pq.top().first+a[i];
            pq.emplace(dp[i], i);
            // cout << i << " - " << dp[i] << " - " << p[n]-p[i] << "\n";
            if (dp[i]<=m && p[n]-p[i]<=m) ok = 1;
        }
        if (ok) r = m;
        else l = m+1;
    }
    cout << r << "\n";
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