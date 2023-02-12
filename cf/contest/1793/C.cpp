#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int mn = 1, mx = n, l = 1, r = n;
    while (l < r && (a[l] == mn || a[l] == mx || a[r] == mn || a[r] == mx)) {
        if (a[l] == mn)
            mn++, l++;
        else if (a[l] == mx)
            mx--, l++;
        else if (a[r] == mn)
            mn++, r--;
        else if (a[r] == mx)
            mx--, r--;
    }
    if (l != r) {
        cout << l << " " << r << "\n";
    } else {
        cout << "-1\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}