#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 30
using namespace std;

void sol()
{
    int n, p;
    cin >> n >> p;
    int cnt = n * 2 + p;
    for (int i = 1;; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << " " << (j + i) % n + 1 << "\n";
            if (--cnt == 0)
                return;
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