#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s, t;
    cin >> s >> t;
    int a = count(s.begin(), s.end(), '1'), b = count(t.begin(), t.end(), '1');
    cout << ((a + 1) / 2 >= (b + 1) / 2 ? "YES\n" : "NO\n");
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