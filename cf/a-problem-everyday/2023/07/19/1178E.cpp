
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    int n = s.size();
    if (n <= 3) {
        cout << s[0] << "\n";
        return;
    }
    string ans;
    for (int i = 0; i + 1 < n / 2; i += 2) {
        if (s[i] == s[n - 1 - i] || s[i] == s[n - 2 - i])
            ans.push_back(s[i]);
        else
            ans.push_back(s[i + 1]);
    }
    cout << ans;
    reverse(ans.begin(), ans.end());
    if (n / 2 % 2)
        cout << s[n / 2];
    cout << ans;
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
