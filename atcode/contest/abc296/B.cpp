#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s[8];
    for (int i = 0; i < 8; i++)
        cin >> s[i];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == '*') {
                cout << char(j + 'a') << 8 - i << "\n";
            }
        }
    }
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