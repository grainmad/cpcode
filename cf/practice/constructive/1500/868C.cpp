#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
using namespace std;

int a[N][4];

void sol()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0, sz = 1 << k; i < sz; i++)
    {
        int zero = 0, one = 0;
        for (int j = 0; j < n; j++)
        {
            int x = 1, y = 1;
            for (int c = 0; c < k; c++)
            {
                if ((i >> c & 1) != a[j][c])
                    x = 0;
            }
            one = max(one, x);
            for (int c = 0; c < k; c++)
            {
                if ((i >> c & 1) && a[j][c] != 0)
                    y = 0;
            }
            zero = max(zero, y);
        }
        if (zero && one)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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