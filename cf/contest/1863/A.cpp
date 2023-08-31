#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, a, q;
    cin >> n >> a >> q;
    string s;
    cin >> s;
    if (a + count(s.begin(), s.end(), '+') < n) {
        cout << "NO\n";
        return;
    }
    int ok = a == n;
    for (char i : s) {
        if (i == '+') {
            a++;
        } else {
            a--;
        }
        if (a >= n)
            ok = 1;
    }
    cout << (ok ? "YES" : "MAYBE") << "\n";
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