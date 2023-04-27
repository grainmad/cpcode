
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1005
#define MOD 998244353
using namespace std;

/*

prod((1-a[i])) sum(a[i]/(1-a[i]))

*/

double a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (a[n - 1] == 1) {
        cout << "1\n";
        return;
    }
    double P = 1, S = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (S > 1)
            break;
        S += a[i] / (1 - a[i]);
        P *= (1 - a[i]);
    }
    cout.precision(12);
    cout << P * S << "\n";
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