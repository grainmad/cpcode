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
    int mx = *max_element(a.begin(), a.end());
    int mn = *min_element(a.begin(), a.end());
    if (mx >= 0 && mn >= 0) {
        cout << n - 1 << "\n";
        for (int i = 2; i <= n; i++) {
            cout << i << " " << i - 1 << endl;
        }
    } else if (mx <= 0 && mn <= 0) {
        cout << n - 1 << "\n";
        for (int i = n - 1; i >= 1; i--) {
            cout << i << " " << i + 1 << endl;
        }
    } else if (mx > -mn) {
        int p = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == mx)
                p = i;
        p++;
        vector<pair<int, int>> ans;
        ans.emplace_back(n, p);
        a[n - 1] += a[p - 1];
        ans.emplace_back(n, p);
        a[n - 1] += a[p - 1];
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                while (a[i - 1] - a[i] > a[n - 1]) {
                    a[n - 1] *= 2;
                    ans.emplace_back(n, n);
                }
                a[i] += a[n - 1];
                ans.emplace_back(i + 1, n);
            }
            // for (int j : a) {
            //     cout << j << " ";
            // }
            // cout << endl;
        }
        cout << ans.size() << "\n";
        for (auto [i, j] : ans) {
            cout << i << " " << j << "\n";
        }
    } else {
        int p = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == mn)
                p = i;
        p++;
        vector<pair<int, int>> ans;
        ans.emplace_back(1, p);
        a[0] += a[p - 1];
        ans.emplace_back(1, p);
        a[0] += a[p - 1];
        for (int i = n - 1; i >= 1; i--) {
            if (a[i - 1] > a[i]) {
                while (a[i - 1] + a[0] > a[i]) {
                    a[0] *= 2;
                    ans.emplace_back(1, 1);
                }
                a[i - 1] += a[0];
                ans.emplace_back(i, 1);
            }
        }
        cout << ans.size() << "\n";
        for (auto [i, j] : ans) {
            cout << i << " " << j << "\n";
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