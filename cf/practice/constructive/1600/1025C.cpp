#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    int ans = 1;
    for (int i = 1, p = 1; i < 2 * n; i++) {
        if (s[i % n] != s[(i - 1) % n])
            p++;
        else
            p = 1;
        ans = max(ans, p);
    }
    cout << min(ans, n) << endl;
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