#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    int mx = 0, mn = 0;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int b = count(s.begin(), s.end(), '1');
        int mx_t2 = 0, mn_t2 = 0, c1 = 1, c2 = 1;
        for (int j = 1; j < m; j++) {
            if (s[j - 1] == s[j] && s[j] == '1') {
                c1++;

                mn_t2 += c2 / 2;
                c2 = 1;
            } else {
                mx_t2 += c1 / 2;
                c1 = 1;

                c2++;
            }
        }
        mx_t2 += c1 / 2;
        mn_t2 += c2 / 2;
        // cout << "---------\n";
        // cout << s << endl;
        // cout << mx_t2 << " " << mn_t2 << endl;
        // cout << b - min(mx_t2, m / 4) << " " << b - max(0, m / 4 - mn_t2)
        //      << endl;
        mn += b - min(mx_t2, m / 4);
        mx += b - max(0, m / 4 - mn_t2);
    }
    cout << mn << " " << mx << "\n";
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