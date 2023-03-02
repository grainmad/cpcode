#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

string s = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFBFBFFB";
void sol() {
    int n;
    string u;
    cin >> n >> u;
    for (int i = n; i < s.size(); i++) {
        if (s.substr(i - n, n) == u) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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