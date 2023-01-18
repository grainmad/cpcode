#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    if (s[k - 1] != s[0])
        cout << s[k - 1] << "\n";
    else if (s[k] != s.back())
        cout << s.substr(k - 1) << "\n";
    else
        cout << s[0] + string((n - k + k - 1) / k, s[k]) << "\n";
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