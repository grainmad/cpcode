#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    int prf = 0, suf = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i - 1] >= a[i])
            suf++;
    }

    int ans = suf;
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && a[i] >= a[i + 1])
            suf--;
        if (i && a[i - 1] <= a[i])
            prf++;
        ans = min(ans, prf + suf + 1);
    }
    cout << ans << "\n";
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
