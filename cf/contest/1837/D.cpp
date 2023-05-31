#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    string s;
    cin >> n >> s;
    if (n % 2 || count(s.begin(), s.end(), '(') != n / 2) {
        cout << "-1\n";
        return;
    }
    vector<int> ans(n, 1);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(')
            c++;
        else
            c--;
        if (c < 0)
            ans[i] = 1;
        else if (c > 0)
            ans[i] = 2;
        else
            ans[i] = ans[i - 1];
    }
    int sz = count(ans.begin(), ans.end(), 1);
    if (sz == 0 || sz == n) {
        cout << "1\n";
        for (int i = 0; i < n; i++)
            cout << "1 ";
    } else {
        cout << "2\n";
        for (int i : ans) {
            cout << i << " ";
        }
    }
    cout << "\n";
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