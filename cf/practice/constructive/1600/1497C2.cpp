#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol()
{
    ll n, k;
    cin >> n >> k;
    ll s = n - k + 3;
    for (int i = 0; i < k - 3; i++)
    {
        cout << "1 ";
    }
    if (s % 2)
    {
        cout << "1 " << s / 2 << " " << s / 2 << endl;
    }
    else if (s % 4 == 0)
    {
        cout << s / 4 << " " << s / 4 << " " << s / 2 << endl;
    }
    else
    {
        cout << "2 " << s / 2 - 1 << " " << s / 2 - 1 << endl;
    }
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