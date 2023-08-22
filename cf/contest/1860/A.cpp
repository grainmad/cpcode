#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    int ok = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == ')' && s[i] == '(')
            ok = 1;
    }
    if (ok) {
        cout << "YES\n";
        cout << string(n, '(') + string(n, ')') << "\n";
    } else {
        if (n == 2 && s == "()")
            cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << "()";
            }
            cout << "\n";
        }
    }
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