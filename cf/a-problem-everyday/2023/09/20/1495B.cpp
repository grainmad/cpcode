
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), l(n), r(n);
    for (auto& i : a)
        cin >> i;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i])
            l[i] = l[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1])
            r[i] = r[i + 1] + 1;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max({mx, l[i], r[i]});
    }
    if (mx % 2) {
        cout << "0\n";
        return;
    }
    int cntmx = 0;
    for (int i = 0; i < n; i++) {
        if (l[i] == mx || r[i] == mx)
            cntmx++;
    }
    if (cntmx != 1) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (l[i] == mx && r[i] == mx) {
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
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
