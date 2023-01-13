#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
using namespace std;

void sol()
{
    int n, k, a, b;
    char ch1 = 'G', ch2 = 'B';
    cin >> n >> k >> a >> b;
    if (a < b)
        swap(a, b), swap(ch1, ch2);
    if ((a + b) / (b + 1) > k)
    {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < b; i++)
    {
        cout << string(a / (b + 1) + (i < a % (b + 1) ? 1 : 0), ch1);
        cout << ch2;
    }
    cout << string(a / (b + 1), ch1);
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