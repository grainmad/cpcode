#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string u, v;
    cin >> u >> v;
    reverse(u.begin(), u.end());
    reverse(v.begin(), v.end());
    if (u.size() > v.size())
        swap(u, v);
    while (u.size() != v.size())
        u.push_back('0');
    reverse(u.begin(), u.end());
    reverse(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        if (u[i] != v[i]) {
            ans += abs(u[i] - v[i]);
            ans += (v.size() - i - 1) * 9;
            break;
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
