#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

ll a[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n == 1) {
        cout << "1 1\n-1\n1 1\n1\n1 1\n" << -a[1] << "\n";
        return;
    }
    cout << "1 1\n";
    cout << -a[1] << "\n";
    a[1] = 0;
    cout << "2 " << n << "\n";
    for (int i = 2; i <= n; i++) {
        cout << a[i] * (n - 1) << " ";
        a[i] += a[i] * (n - 1);
    }
    cout << "\n1 " << n << "\n";
    for (int i = 1; i <= n; i++) {
        cout << -a[i] << " ";
    }
    cout << "\n";
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