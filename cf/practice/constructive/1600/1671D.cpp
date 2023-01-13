#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 200005
using namespace std;

int n, x;
ll a[N];

void ist(int p, int val)
{
    for (int i = n; i > p; i--)
    {
        a[i] = a[i - 1];
    }
    a[p] = val;
    n++;
}

void sol()
{

    cin >> n >> x;
    ll mx = 0, mn = N;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    if (mx < x)
    {
        ll val = abs(a[0] - x), p = 0;
        if (val > abs(a[n - 1] - x))
            val = abs(a[n - 1] - x), p = n;
        for (int i = 1; i < n; i++)
        {
            if (val > abs(x - a[i]) + abs(x - a[i - 1]) - abs(a[i] - a[i - 1]))
            {
                val = abs(x - a[i]) + abs(x - a[i - 1]) - abs(a[i] - a[i - 1]);
                p = i;
            }
        }
        ist(p, x);
    }
    if (1 < mn)
    {
        ll val = abs(a[0] - 1), p = 0;
        if (val > abs(a[n - 1] - 1))
            val = abs(a[n - 1] - 1), p = n;
        for (int i = 1; i < n; i++)
        {
            if (val > abs(1 - a[i]) + abs(1 - a[i - 1]) - abs(a[i] - a[i - 1]))
            {
                val = abs(1 - a[i]) + abs(1 - a[i - 1]) - abs(a[i] - a[i - 1]);
                p = i;
            }
        }
        ist(p, 1);
    }

    // for (int i=0; i<n; i++) {
    // 	cout << a[i] << " ";
    // } cout<< endl;
    ll cnt = 0;
    for (int i = 1; i < n; i++)
    {
        cnt += abs(a[i] - a[i - 1]);
    }
    cout << cnt << "\n";
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