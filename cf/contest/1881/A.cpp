#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    auto ok = [&]() {
        for (int i = 0; i + t.size() <= s.size(); i++) {
            if (s.substr(i, t.size()) == t)
                return true;
        }
        return false;
    };
    int ans = 0;
    while (s.size() <= 100) {
        if (ok()) {
            cout << ans << "\n";
            return;
        }
        ans++;
        s += s;
    }
    cout << "-1\n";
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