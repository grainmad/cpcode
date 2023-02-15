#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 12
#define MOD 998244353
using namespace std;

int n, m;
string s[N];

bool check(string& u) {
    for (int i = 0; i < n; i++) {
        int dif = 0;
        for (int j = 0; j < m; j++) {
            dif += s[i][j] != u[j];
        }
        if (dif > 1)
            return false;
    }
    return true;
}

void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    string ans = s[0];
    for (int i = 0; i < m; i++) {
        char ch = ans[i];
        for (char j = 'a'; j <= 'z'; j++) {
            ans[i] = j;
            if (check(ans)) {
                cout << ans << "\n";
                return;
            }
        }
        ans[i] = ch;
    }
    cout << "-1\n";
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