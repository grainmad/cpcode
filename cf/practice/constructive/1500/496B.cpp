#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol()
{
    int n;
    string s;
    cin >> n >> s;
    int p = 0;
    for (int i = 1; i < n; i++)
    {
        char a = s[p], b = s[i];
        bool ok = 0;
        for (int j = 0; j < n; j++)
        {
            int x = (s[(p + j) % n] - a + 10) % 10, y = (s[(i + j) % n] - b + 10) % 10;
            if (x < y)
            {
                ok = 0;
                break;
            }
            else if (x > y)
            {
                ok = 1;
                break;
            }
        }
        if (ok)
            p = i;
    }
    for (int i = 0; i < n; i++)
    {
        cout << char((s[(i + p) % n] - s[p] + 10) % 10 + '0');
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