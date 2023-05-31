#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] || a[i] == '1' && b[i] == 'l' ||
            a[i] == 'l' && b[i] == '1' || a[i] == 'o' && b[i] == '0' ||
            a[i] == '0' && b[i] == 'o') {
            cnt++;
        }
    }
    cout << (cnt == n ? "Yes\n" : "No\n");
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