#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (d > s[i] - '0') {
            cout << s.substr(0, i) << d << s.substr(i) << "\n";
            return;
        }
    }
    cout << s << d << "\n";
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