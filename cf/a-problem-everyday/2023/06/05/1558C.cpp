
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == i % 2) {
            cout << "-1\n";
            return;
        }
    }
    vector<int> ans;
    auto se = [&](int x) -> pair<int, int> {
        int s = find(a.begin(), a.end(), x - 1) - a.begin();
        int e = find(a.begin(), a.end(), x) - a.begin();
        return {s + 1, e + 1};
    };
    auto rvs = [&](int x) {
        reverse(a.begin(), a.begin() + x);
        ans.push_back(x);
    };
    int p = n;
    se(p);
    while (p > 1) {
        auto [s, e] = se(p);
        // cout << s << " " << e << '\n';
        if (s == p - 1 && e == p) {
            p -= 2;
        } else if (s == 2 && e == 1) {
            rvs(p);
        } else if (s + 1 == e) {
            rvs(e);
        } else if (e + 1 == s) {
            rvs(s + 1);
        } else if (e == 1) {
            rvs(s - 1);
        } else {
            rvs(e);
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << ' ';
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
