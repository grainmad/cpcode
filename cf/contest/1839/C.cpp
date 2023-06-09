#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    if (a.back() == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<int> ans;
    int p = n - 1;
    while (p >= 0) {
        if (p > 0 && a[p - 1] == 0)
            ans.push_back(0), p--;
        else {
            int c = p - 1;
            while (c >= 0 && a[c] == 1)
                c--;
            for (int i = 0; i < p - c - 1; i++) {
                ans.push_back(0);
            }
            ans.push_back(p - c - 1);
            p = c;
        }
    }
    for (int i : ans) {
        cout << i << " ";
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