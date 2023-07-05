#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k, x;
    cin >> n >> k >> x;
    // cout << n << " " << k << " " << x << endl;
    vector<int> ans;
    for (int i = 1; i <= k; i++) {
        if (x == i)
            continue;
        while (n >= i) {
            ans.push_back(i);
            n -= i;
        }
    }
    if (n == 0) {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    } else {
        if (ans.size())
            ans.back() += n;
        if (ans.size() && ans.back() != x && ans.back() <= k) {
            cout << "YES\n";
            cout << ans.size() << "\n";
            for (int i : ans) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            cout << "NO\n";
        }
    }
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