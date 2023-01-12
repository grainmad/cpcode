#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol()
{
    int n;
    cin >> n;
    std::vector<ll> v(n);
    std::vector<ll> p(n + 1);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] + v[i - 1];
    cout << *max_element(p.begin(), p.end()) - *min_element(p.begin(), p.end()) << "\n";
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