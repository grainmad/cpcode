#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    vector<int> a(5);
    for (int i = 0; i < 4; i++) {
        if (s[i] == '0')
            a[i] = 10;
        else
            a[i] = s[i] - '0';
    }
    int cnt = 4 + abs(a[0] - 1);
    for (int i = 1; i < 4; i++) {
        cnt += abs(a[i] - a[i - 1]);
    }
    cout << cnt << "\n";
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