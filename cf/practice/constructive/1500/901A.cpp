#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

int a[N];

void sol()
{
    int n, ok = 1, s = 0;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
        s += a[i];
        if (i > 0 && a[i] != 1 && a[i - 1] != 1)
            ok = 0;
    }
    if (ok)
        cout << "perfect\n";
    else
    {
        cout << "ambiguous\n";
        int pre = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < a[i]; j++)
            {
                cout << pre << " ";
            }
            pre += a[i];
        }
        cout << "\n";
        pre = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < a[i]; j++)
            {
                if (i > 0 && a[i - 1] != 1 && a[i] != 1 && j == a[i] - 1)
                {
                    cout << pre - 1 << " ";
                }
                else
                    cout << pre << " ";
            }
            pre += a[i];
        }
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