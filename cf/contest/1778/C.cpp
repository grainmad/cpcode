#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll ans = 0;
int n, k;
int cur[200];
string a, b;

void dfs(string& s, int p, int cnt) {
    if (s.size() < k - cnt + p) {
        return;
    }
    if (cnt == k) {
        ll ac = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cur[a[i]] || a[i] == b[i]) {
                cnt++;
            } else
                cnt = 0;
            ac += cnt;
        }
        ans = max(ans, ac);
        return;
    }
    cur[s[p]] = 1;
    dfs(s, p + 1, cnt + 1);
    cur[s[p]] = 0;
    dfs(s, p + 1, cnt);
}

void sol() {
    ans = 0;
    memset(cur, 0, sizeof(cur));
    cin >> n >> k;
    cin >> a >> b;
    set<char> st;
    for (char i : a)
        st.insert(i);
    if (st.size() <= k) {
        cout << ((1LL + n) * n / 2) << "\n";
        return;
    }
    string s(st.begin(), st.end());
    dfs(s, 0, 0);
    cout << ans << "\n";
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