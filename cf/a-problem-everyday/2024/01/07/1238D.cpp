
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = n*(n-1)/2;
    s = "#"+s+"#";
    int p = 0;
    for (int i=1; i<=n; i++) {
        if (s[i] != s[i+1]) {
            if(p!=0) ans -= i-p;
            p = i;
        }
    }
    p = n+1;
    for (int i=n; i>=1; i--) {
        if (s[i] != s[i-1]) {
            if (p!=n+1) ans -= p-i-1;
            p = i;
        }
    }
    cout << ans << "\n";
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
