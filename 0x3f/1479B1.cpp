#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> nxt(n + 1);
    for (int& i : a)
        cin >> i;
    for (int i = n - 1; i >= 0; i--) {
        nxt[a[i]].push_back(i);
    }
    vector<int> a0(1, 0), a1(1, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] == a0.back()) {
            a1.push_back(a[i]);
        } else if (a[i] == a1.back()) {
            a0.push_back(a[i]);
        } else {
            int x = n, y = n;
            if (nxt[a0.back()].size()) {
                x = nxt[a0.back()].back();
                nxt[a0.back()].pop_back();
            }
            if (nxt[a1.back()].size()) {
                y = nxt[a1.back()].back();
                nxt[a1.back()].pop_back();
            }
            if (x < y) {
                a0.push_back(a[i]);
            } else {
                a1.push_back(a[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0, p = 0; i < a0.size(); i++) {
        if (a0[i] != a0[p]) {
            ans++;
            p = i;
        }
    }
    for (int i = 0, p = 0; i < a1.size(); i++) {
        if (a1[i] != a1[p]) {
            ans++;
            p = i;
        }
    }
    cout << ans << "\n";
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