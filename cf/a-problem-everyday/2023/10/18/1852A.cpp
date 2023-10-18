
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll& i:a) cin >> i;
    vector<pair<ll,ll>> p; 
    if (a[0] != 1) p.emplace_back(a[0]-1, 1);
    for (int i=1; i<n; i++) {
        if (a[i] != 1+a[i-1]) p.emplace_back(a[i]-a[i-1]-1, a[i-1]+1);
    }
    p.emplace_back(1e15, a[n-1]+1);
    // for (auto [i,j]:p) {
    //     cout << i << " " << j << endl;
    // }
    ll j = 0, c = 1, stp = 0;
    for (int i=0; i<k; i++) {
        while (p[j].first+stp < c) {
            stp += p[j].first;
            j++;
        }
        c = p[j].second + c-stp - 1;
        // if (c > a[n-1]) break;
    }
    cout << c << "\n";
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
