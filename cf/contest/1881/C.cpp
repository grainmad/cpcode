#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n - 1), ans(n);
    for (int& i : a)
        cin >> i;
    for (int i = 0; i < n - 1; i++) {
        if (i > 0 && a[i - 1] < a[i]) {
            ans[i] = a[i - 1];
            ans[i + 1] = a[i];
        } else {
            ans[i] = a[i];
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
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