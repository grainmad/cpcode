#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    vector<int> f(n + 1, INF);
    f[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        f[i] = f[i + 1] + 1;
        if (i + a[i] < n) {
            f[i] = min(f[i], f[i + a[i] + 1]);
        }
    }
    cout << f[0] << "\n";
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