#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol()
{
    ll x, y;
    cin >> x >> y;
    if (x > y)
        cout << x + y << endl;
    else
        cout << y - y % x / 2 << endl;
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