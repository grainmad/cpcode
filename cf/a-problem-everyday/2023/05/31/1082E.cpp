
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

int a[N];
int p[N];
int pre[N];
vector<int> g[N];

int max_seg(vector<int>& s) {
    int mx = 0, cur = 0;
    for (int i = 0; i < s.size(); i++) {
        cur = max(cur + s[i], 0);
        mx = max(mx, cur);
    }
    return mx;
}

void sol() {
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + (a[i] == c);
    }
    for (int i = 1; i <= n; i++) {
        g[a[i]].push_back(-(p[i] - p[pre[a[i]]]));
        g[a[i]].push_back(1);
        pre[a[i]] = i;
    }
    int ans = 0;
    for (int i = 1, sz = *max_element(a + 1, a + n + 1); i <= sz; i++) {
        if (i == c)
            continue;
        // for (int j : g[i]) {
        //     cout << j << " ";
        // }
        // cout << "\n";
        ans = max(ans, max_seg(g[i]));
    }
    cout << p[n] + ans << "\n";
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
