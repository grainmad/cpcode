#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<string> s(2 * n - 2);
    for (int i = 0; i < 2 * n - 2; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end(),
         [&](auto& a, auto& b) { return a.size() < b.size(); });
    for (int i = 1; i < s.size(); i += 2) {
        reverse(s[i].begin(), s[i].end());
        if (s[i] != s[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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