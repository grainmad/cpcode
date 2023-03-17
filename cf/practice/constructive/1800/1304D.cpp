#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> mn(n), mx(n);
    for (int i = 0; i < n; i++) {
        mn[i] = n - i;
        mx[i] = i + 1;
    }
    int p = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[p] != s[i]) {
            if (s[p] == '>') {
                reverse(mx.begin() + p, mx.begin() + i + 1);
            } else {
                reverse(mn.begin() + p, mn.begin() + i + 1);
            }
            p = i;
        }
    }
    if (s[p] == '>') {
        reverse(mx.begin() + p, mx.end());
    } else {
        reverse(mn.begin() + p, mn.end());
    }
    for (int i : mn) {
        cout << i << " ";
    }
    cout << "\n";
    for (int i : mx) {
        cout << i << " ";
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