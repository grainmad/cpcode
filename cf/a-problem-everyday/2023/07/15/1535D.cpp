
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    reverse(s.begin(), s.end());
    for (auto& i : s) {
        if (i == '1')
            i = '0';
        else if (i == '0')
            i = '1';
    }
    // cout << s << endl;
    int sz = (1 << n) - 1;
    vector<int> v(1 << n + 1, 1);
    for (int i = sz - 1; i >= 0; i--) {
        if (s[i] == '1')
            v[i] = v[2 * i + 2];
        if (s[i] == '0')
            v[i] = v[2 * i + 1];
        if (s[i] == '?')
            v[i] = v[2 * i + 1] + v[2 * i + 2];
    }
    while (q--) {
        int p;
        string c;
        cin >> p >> c;
        p = sz - p;
        if (c[0] != '?')
            c[0] = 1 - (c[0] - '0') + '0';
        s[p] = c[0];
        while (1) {
            if (s[p] == '1')
                v[p] = v[p * 2 + 2];
            if (s[p] == '0')
                v[p] = v[p * 2 + 1];
            if (s[p] == '?')
                v[p] = v[2 * p + 1] + v[2 * p + 2];
            if (p == 0)
                break;
            p = (p - 1) / 2;
        }
        cout << v[0] << "\n";
    }
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
