#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int mp[200];

void sol() {
    for (int i = 0, j = 1; i < 5; i++, j *= 10) {
        mp['A' + i] = j;
    }
    string s;
    cin >> s;
    int n = s.size();
    int ans = -2e9;
    auto cnt = [&]() {
        int rt = 0;
        char mx = 'A';
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] < mx)
                rt -= mp[s[i]];
            else
                rt += mp[s[i]];
            mx = max(mx, s[i]);
        }
        ans = max(ans, rt);
    };
    for (char i = 'A'; i <= 'E'; i++) {
        for (char j = 'A'; j <= 'E'; j++) {
            auto p = s.find_first_of(i);
            if (p != string::npos) {
                s[p] = j;
                cnt();
                s[p] = i;
            }
            p = s.find_last_of(i);
            if (p != string::npos) {
                s[p] = j;
                cnt();
                s[p] = i;
            }
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