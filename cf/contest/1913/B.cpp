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
    int c0 = count(s.begin(), s.end(), '0'), c1 = n-c0;
    int ans = 0;
    for (int i=0; i<n ; i++) {
        if (s[i] == '0') {
            if (c1>0) c1--, ans++;
            else break;
        } else {
            if (c0>0) ans++, c0--;
            else break;
        }
    }
    cout << n-ans << "\n";
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