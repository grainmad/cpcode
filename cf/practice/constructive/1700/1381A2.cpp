#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> ans;
    for (int i = 1; i < n; i++) {
        if (s1[i] != s1[i - 1]) {
            ans.push_back(i);
        }
    }
    if (s1[n - 1] == '1')
        ans.push_back(n);
    char cur = '0';
    for (int i = n - 1; i >= 0; i--) {
        if (cur == s2[i])
            continue;
        ans.push_back(i + 1);
        cur = s2[i];
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
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