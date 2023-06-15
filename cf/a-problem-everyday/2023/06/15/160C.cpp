
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    ll n, k;
    cin >> n >> k;
    k--;
    vector<ll> a(n);    
    map<ll,int> mp;
    for (ll& i:a) cin >> i, mp[i]++;
    sort(a.begin(), a.end());
	ll s = k/n, e = s;
    while (s!=-1 && a[s] == a[e]) s--;
    ll m = k-(s+1)*n+1;
    // cout << m << " " << mp[a[e]] << "\n";
    cout << a[k/n] << " " << a[(m+mp[a[e]]-1)/mp[a[e]]-1] << "\n";
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
