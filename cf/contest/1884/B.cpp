#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int p0 = 0;
    ll opt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            p0 = max(p0, i);
            while (p0 < n && s[p0] == '1')
                p0++;
            if (p0 == n)
                opt = -1;
            else {
                opt += (p0 - i);
                s[i] = '0';
                s[p0] = '1';
            }
        }
        cout << opt << " ";
    }
    cout << "\n";
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