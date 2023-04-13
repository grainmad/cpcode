#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    int p = n;
    while (p > 0 && k >= p) {
        k -= p;
        p--;
        ans.push_back(1000);
    }
    if (k != 0) {
        for (int i = 1; i < k; i++)
            ans.push_back(-1);
        ans.push_back(50);
        ans.push_back(-100);
    }
    while (ans.size() < n)
        ans.push_back(-1);
    // cout << ans.size() << endl;
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