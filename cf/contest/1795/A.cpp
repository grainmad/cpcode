#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

bool check(const string& s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            return false;
    }
    return true;
}

void sol() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    a += b;
    for (int i = 0; i < n + m; i++) {
        if (check(a.substr(0, i)) && check(a.substr(i))) {
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