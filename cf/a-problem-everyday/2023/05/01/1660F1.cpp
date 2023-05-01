
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0, c = 0, t = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '+')
                a++, c += t / 2, t = 0;
            if (s[j] == '-')
                b++, t++;
            if (b >= a && (b - a) % 3 == 0 && (b - a) / 3 <= c + t / 2)
                ans++;
        }
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
