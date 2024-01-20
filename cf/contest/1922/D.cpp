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
    vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> c(n + 1);
    vector<pair<int, int>> p;

    for (int i = 1; i <= n; i++) {
        if (a[i - 1] + a[i + 1] > b[i])
            c[i] = 1;
    }
    int a0 = count(c.begin(), c.end(), 1);
    cout << a0;
    p.emplace_back(0, 0);
    for (int i = 1; i <= n; i++) {
        if (c[i] == 1)
            continue;
        int j = i;
        while (j <= n && c[j] == c[i])
            j++;
        p.emplace_back(i, j - 1);
        i = j - 1;
    }
    p.emplace_back(n + 1, n + 1);
    // for (auto [i, j] : p) {
    //     cout << i << " - " << j << ", ";
    // }
    // cout << endl;
    auto check = [&](int x, int m, int y) {
        if (a[x] + a[y] > b[m])
            return true;
        return false;
    };
    for (int _ = 2; _ <= n; _++) {
        if (a0 == 0) {
            cout << " 0";
            continue;
        }
        auto q = p;
        int cnt = 0;
        for (int i = 1; i + 1 < p.size(); i++) {
            if (p[i].first == p[i].second) {
                if (check(p[i - 1].second, p[i].first, p[i + 1].first)) {
                    cnt++;
                    q[i].first++;
                }
            } else {
                if (check(p[i - 1].second, p[i].first, p[i].first + 1)) {
                    cnt++;
                    q[i].first++;
                }
                if (check(p[i].second - 1, p[i].second, p[i + 1].first)) {
                    cnt++;
                    q[i].second--;
                }
            }
        }
        int t = 0;
        for (int i = 0; i < q.size(); i++) {
            if (q[i].first <= q[i].second) {
                q[t++] = q[i];
            }
        }
        while (q.size() != t) {
            q.pop_back();
        }
        p = q;
        cout << " " << cnt;
        a0 = cnt;
    }
    cout << endl;
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