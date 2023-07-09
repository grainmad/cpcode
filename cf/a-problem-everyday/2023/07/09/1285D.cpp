
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 100005
#define MOD 998244353
using namespace std;

int a[N];
int ans = (1 << 30) - 1;

void dfs(int lev, int l, int r, int num) {
    // cout << lev << ' ' << l << ' ' << r << ' ' << num << endl;
    if (lev == -1) {
        ans = min(ans, num);
        return;
    }
    if ((a[l] >> lev & 1) != (a[r] >> lev & 1)) {
        int p = l;
        while ((a[p] >> lev & 1) == (a[l] >> lev & 1))
            p++;
        dfs(lev - 1, l, p - 1, num << 1 | 1);
        dfs(lev - 1, p, r, num << 1 | 1);
    } else {
        dfs(lev - 1, l, r, num << 1);
    }
}

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    dfs(29, 0, n - 1, 0);
    cout << ans << "\n";
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
