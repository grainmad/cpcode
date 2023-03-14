#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void swp(int l, int r, string& s) {
    while (l < r) {
        swap(s[l++], s[r--]);
    }
}

void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<int, int>> ans;
    int l = 0, r = n - 1;
    while (l < r) {
        if (s[l] == '(')
            l++;
        else if (s[r] == ')')
            r--;
        else if (s[l] == ')' && s[r] == '(') {
            ans.emplace_back(l, r);
            swp(l, r, s);
        }
    }
    // cout << s << endl;
    l = 1, r = n / 2;
    while (--k) {
        ans.emplace_back(l, r);
        swp(l, r, s);
        l += 2;
        r++;
    }
    // cout << s << endl;
    cout << ans.size() << "\n";
    for (auto [x, y] : ans) {
        cout << x + 1 << " " << y + 1 << "\n";
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