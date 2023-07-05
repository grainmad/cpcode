#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define INF 0x3f3f3f3f
#define MOD 998244353

using namespace std;

string s;
int m;
string l, r;

void sol() {
    cin >> s >> m >> l >> r;
    s = '+' + s;
    int n = s.size();
    vector<vector<int>> suf(n + 2, vector<int>(10, INF));
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1];
        suf[i][s[i + 1] - '0'] = i + 1;
    }
    int cur = 0;
    for (int i = 0; i < m; i++) {
        int p = l[i] - '0';
        for (int j = l[i] - '0'; j <= r[i] - '0'; j++) {  // 寻找最靠右的
            if (suf[cur][j] > suf[cur][p])
                p = j;
        }
        cur = suf[cur][p];
        if (cur >= n) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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