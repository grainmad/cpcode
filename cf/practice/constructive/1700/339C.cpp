#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<int> ans;
vector<int> p;
int n, one;

int f[1005][10][11];  // f[i][j][k] 第i次放置数为p[j]，能否产生k的差距。
// f[n][][] = 1;
// f[i+1][c][p[c]-k] = f[i][j][k], c != j and p[c]>k

int dfs(int i, int j, int k) {
    if (i == n)
        return 1;
    if (f[i][j][k])
        return f[i][j][k];
    for (int c = 0; c < one; c++) {
        if (c != j && p[c] > k) {
            if (dfs(i + 1, c, p[c] - k) == 1) {
                ans.push_back(p[c]);
                return f[i][j][k] = 1;
            }
        }
    }
    return f[i][j][k] = -1;
}

void sol() {
    string s;
    cin >> s >> n;

    for (int i = 0; i < 10; i++) {
        if (s[i] == '1')
            p.push_back(i + 1);
    }
    one = count(s.begin(), s.end(), '1');
    if (one == 0) {
        cout << "NO\n";
    } else {
        for (int i = 0; i < one; i++) {
            if (dfs(1, i, p[i]) != -1) {
                ans.push_back(p[i]);
                cout << "YES\n";
                reverse(ans.begin(), ans.end());
                for (int i : ans) {
                    cout << i << " ";
                }
                return;
            }
        }
        cout << "NO\n";
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