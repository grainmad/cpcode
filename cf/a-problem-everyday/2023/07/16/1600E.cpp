
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
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    vector<int> l(n, 1), r(n, 1);
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i])
            l[i] += l[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] > a[i])
            r[i] += r[i + 1];
    }
    auto dfs = [&](auto self, int x, int y, int p) -> bool {
        // cout << x << " " << y << "\n";
        if (x == y)
            return a[x] > p;
        if (a[x] <= p && a[y] <= p)
            return false;
        if (a[x] <= p)
            return !self(self, x, y - 1, a[y]);
        if (a[y] <= p)
            return !self(self, x + 1, y, a[x]);
        if (a[x] > a[y]) {
            if (r[x] % 2)
                return true;
            return !self(self, x, y - 1, a[y]);
        } else if (a[x] < a[y]) {
            if (l[y] % 2)
                return true;
            return !self(self, x + 1, y, a[x]);
        } else
            return l[y] % 2 || r[x] % 2;
    };
    cout << (dfs(dfs, 0, n - 1, -1) ? "Alice\n" : "Bob\n");
}

void sol2() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    int l = 0, r = n - 1;
    while (l + 1 < n && a[l + 1] > a[l])
        l++;
    while (r - 1 >= 0 && a[r - 1] > a[r])
        r--;
    l = l + 1;
    r = n - r;
    cout << ((l % 2 || r % 2) ? "Alice\n" : "Bob\n");
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
    // sol2();
#endif
    return 0;
}
