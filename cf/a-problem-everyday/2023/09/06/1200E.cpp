
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 1000005
using namespace std;

#define ull unsigned long long
const ull MOD = 998244353, BASE = 171;

// string s[] index from 0 to n-1
// B[i] = BASE^i
// s[i...j] = s[0...j] - s[0...i-1]
// hash s[0...i-1] = H[i] = s[0]*B[i-1]+s[1]*B[i-2]+...+s[i-1]*B[0]
// hash s[0...j] = H[j+1] = s[0]*B[j]+s[1]*B[j-1]+...+s[j]*B[0]
// hash s[i...j] = H[j+1] - H[i]*B[j-i+1]
// hash s[i...j-1] = H[j] - H[i]*B[j-i]
// for (int i=1; i<=n; i++) {
//     H[i] = (H[i-1]*BASE%MOD + s[i-1])%MOD;
// }

ull H[N], B[N];

void sol() {
    auto hash = [&](int l, int r) {  // hash of s[l...r-1]
        return (H[r] - H[l] * B[r - l] % MOD + MOD) % MOD;
    };
    B[0] = 1;
    for (int i = 1; i < N; i++) {
        B[i] = B[i - 1] * BASE % MOD;
    }
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    ull sz = 0;
    for (char i : s[0]) {
        H[sz + 1] = (H[sz] * BASE % MOD + i) % MOD;
        sz++;
    }
    string ans = s[0];
    for (int i = 1; i < n; i++) {
        ull ssz = s[i].size();
        ull com = 0, len = min(sz, ssz), sh = 0;
        for (ll j = 1; j <= len; j++) {
            sh = (sh * BASE % MOD + s[i][j - 1]) % MOD;
            if (sh == hash(sz - j, sz))
                com = j;
        }
        // cout << sz << " " << com << endl;
        sz -= com;
        while (com) {
            ans.pop_back();
            com--;
        }
        for (char j : s[i]) {
            ans.push_back(j);
            H[sz + 1] = (H[sz] * BASE % MOD + j) % MOD;
            sz++;
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
