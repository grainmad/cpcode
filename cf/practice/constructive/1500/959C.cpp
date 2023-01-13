#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol()
{
    int n;
    cin >> n;
    if (n < 6)
    {
        cout << "-1\n";
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (i <= n / 2 + 1)
                cout << "1 " << i << "\n";
            else
                cout << "2 " << i << "\n";
        }
    }
    for (int i = 2; i <= n; i++)
    {
        cout << i - 1 << " " << i << "\n";
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