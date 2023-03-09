#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int ch[200];

void sol() {
    string s;
    cin >> s;
    char ch;
    for (char i = 'A'; i <= 'Z'; i++) {
        if (count(s.begin(), s.end(), i) == 2) {
            ch = i;
        }
    }
    int n = s.size(), l = n, r = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ch) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    if (r - l - 1 == 0) {
        cout << "Impossible\n";
        return;
    }
    vector<string> ans(2, string(13, '0'));
    int x = 0, y = 12 - (r - l - 1) / 2, d = 1;
    ans[x][y] = ch;
    for (int i = l + 1; i < r; i++) {
        y += d;
        if (y == 13)
            y--, x++, d = -1;
        ans[x][y] = s[i];
    }
    for (int i = 0; i < 26 - r + l; i++) {
        y += d;
        if (y == -1)
            y++, x--, d = 1;
        ans[x][y] = s[(r + 1 + i) % n];
    }
    cout << ans[0] << "\n" << ans[1] << "\n";
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