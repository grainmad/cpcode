#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    string ss = s, st = t;
    sort(ss.begin(), ss.end());
    sort(st.begin(), st.end());
    if (ss != st) {
        cout << "NO\n";
        return;
    }
    if (n >= 2 * k) {
        cout << "YES\n";
    } else if (n < k) {
        cout << (s == t ? "YES\n" : "NO\n");
    } else {  // k<=n<2k
        int u = n - k;
        // cout << u << endl;
        // cout << s.substr(u, k - u) << endl;
        cout << (s.substr(u, k - u) == t.substr(u, k - u) ? "YES\n" : "NO\n");
    }
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