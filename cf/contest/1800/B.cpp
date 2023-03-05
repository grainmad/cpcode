#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ch[200];
    memset(ch, 0, sizeof(ch));
    for (char i : s)
        ch[i]++;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += min(ch['a' + i], ch['A' + i]);
        int d = min(abs(ch['a' + i] - ch['A' + i]) / 2, k);
        ans += d;
        k -= d;
    }
    cout << ans << "\n";
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