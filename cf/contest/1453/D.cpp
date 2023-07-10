#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n;
    cin >> n;
    if (n % 2) {
        cout << "-1\n";
    } else {
        string ans;
        for (int i = 1; i < 63; i++) {
            if (n >> i & 1) {
                string s(i, '0');
                s[0] = '1';
                s.back() = '1';
                ans += s;
            }
        }
        cout << ans.size() << "\n";
        for (char i : ans) {
            cout << i << " ";
        }
        cout << "\n";
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