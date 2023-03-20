#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    a[0] = 1;
    for (int i = 1, p = 0; i < n; i++) {
        if (s[p] <= s[i])
            a[i] = 1, p = i;
    }
    for (int i = 0, p = -1; i < n; i++) {
        if (a[i])
            continue;
        if (p != -1 && s[p] > s[i]) {
            cout << "NO\n";
            return;
        }
        p = i;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i];
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