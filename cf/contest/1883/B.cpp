#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> c(26);
    for (char i : s) {
        c[i - 'a']++;
    }
    int u = n - k;
    if (u % 2) {
        int f = 1;
        for (int i = 0; i < 26; i++) {
            if (c[i] % 2) {
                if (f)
                    f = 0;
                else
                    c[i] -= 1, k--;
            }
        }
        if (f == 1 || k >= 0 && k % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        for (int i = 0; i < 26; i++) {
            if (c[i] % 2) {
                c[i] -= 1, k--;
            }
        }
        if (k >= 0 && k % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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