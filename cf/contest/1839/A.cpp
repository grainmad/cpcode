#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);

    for (int i = n; i > 0; i -= k) {
        a[i] = 1;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        c += a[i];
        if ((i + k - 1) / k > c) {
            a[i] = 1;
            c++;
        }
    }
    cout << accumulate(a.begin(), a.end(), 0) << "\n";
}

int main() {
    cout << setprecision(15) << fixed;
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