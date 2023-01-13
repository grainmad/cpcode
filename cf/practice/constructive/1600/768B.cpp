#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol()
{
    ll n, l, r;
    cin >> n >> l >> r;
    std::vector<ll> v;
    ll u = n;
    while (u)
    {
        v.push_back((u + 1) / 2);
        u >>= 1;
    }
    reverse(v.begin(), v.end());
    map<ll, ll> mp;
    ll id = 1;
    for (ll i : v)
    {
        mp[id] = i;
        id <<= 1;
        // cout << i << " ";
    }
    // for (auto& i:mp) {
    // 	cout << i.first << " " << i.second << endl;
    // }
    ll ans = 0;
    while (r)
    {
        ans += mp[r & -r];
        r -= r & -r;
    }
    l--;
    while (l)
    {
        ans -= mp[l & -l];
        l -= l & -l;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }
#else
    sol();
#endif
    return 0;
}