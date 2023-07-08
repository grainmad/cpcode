#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    vector<int> b;
    for (int i = 1; i < n; i++) {
        b.push_back(abs(a[i] - a[i - 1]));
        // cout << abs(a[i] - a[i - 1]) << " ";
    }
    // cout << "\n";
    sort(b.begin(), b.end());
    while (--k) {
        b.pop_back();
    }
    cout << accumulate(b.begin(), b.end(), 0LL) << "\n";
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