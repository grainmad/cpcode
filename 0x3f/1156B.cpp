#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

bool check(const string& a) {
    for (int i = 1; i < a.size(); i++) {
        if (abs(a[i] - a[i - 1]) == 1) {
            return false;
        }
    }
    return true;
}

void sol() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string ans[2];
    int p = 0;
    for (char i : s) {
        if (ans[p].size() && ans[p].back() != i) {
            p = 1 - p;
        }
        ans[p].push_back(i);
    }
    if (check(ans[0] + ans[1])) {
        cout << ans[0] + ans[1] << endl;
    } else if (check(ans[1] + ans[0])) {
        cout << ans[1] + ans[0] << endl;
    } else {
        cout << "No answer\n";
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