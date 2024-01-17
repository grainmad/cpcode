
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    vector<int> ans;
    for (int i=0; i<n; i++) {
        int l = 0, r = t.size();
        while (l<r) {
            int m = l+r>>1;
            if (t[m] <= s[i]) {
                r = m;
            } else {
                l = m+1;
            }
        }
        if (r == t.size()) t.push_back(s[i]);
        else t[r] = s[i];
        ans.push_back(r+1);
    }
    cout << t.size() << "\n";
    for (int i:ans) {
        cout << i << " ";
    } cout << "\n";
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
