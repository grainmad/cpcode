#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 300005
#define MOD 998244353
using namespace std;

ll inv[N];

void sol() {
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    ll mul = 1;    
    for (int i=1; i<n-1; i++) {
        if (s[i] == '?') mul *= i, mul %= MOD;
    }
    cout << (s[0] == '?' ? 0 : mul) << "\n";
    for (int i=0; i<m; i++) {
        int p;
        string c;
        cin >> p >> c;
        if (p>1 && s[p-1] == '?' && c[0] != '?') {
            mul *= inv[p-1];
            mul %= MOD;
        }
        if (p>1 && s[p-1] != '?' && c[0] == '?') {
            mul *= p-1;
            mul %= MOD;
        }
        s[p-1] = c[0];
        cout << (s[0] == '?' ? 0 : mul) << "\n";
    }
}

int main() {
    inv[1] = 1;
    for (int i=2; i<N; i++) {
        inv[i] = (MOD-MOD/i) * inv[MOD%i] % MOD;
    }
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