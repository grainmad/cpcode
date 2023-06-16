
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
    vector<int> cnt(201);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int ans = 1;
    for (int i = 1; i <= 200; i++) {
        if (!cnt[i])
            continue;
        // cout << i << endl;
        int mx = *max_element(cnt.begin(), cnt.end());
        // cout << "mx " << mx << endl;
        vector<int> c = cnt, h(n + 1);
        for (int i = 1; i <= 200; i++)
            h[c[i]]++;

        int l = -1, r = n, stp = 1;
        while (l < r) {
            // cout << l << " " << r << endl;
            do {
                l++;
                int v = c[a[l]]--;
                h[v]--;
                if (v)
                    h[v - 1]++;
                if (mx == v && h[v] == 0) {
                    while (v >= 0 && h[v] == 0)
                        v--;
                    mx = v;
                }
            } while (l < r && a[l] != i);
            if (l == r)
                break;
            do {
                r--;
                int v = c[a[r]]--;
                h[v]--;
                if (v)
                    h[v - 1]++;
                if (mx == v && h[v] == 0) {
                    while (v >= 0 && h[v] == 0)
                        v--;
                    mx = v;
                }
            } while (l < r && a[r] != i);
            if (l < r) {
                ans = max(ans, stp * 2 + mx);
                // cout << "ans " << ans << endl;
                stp++;
            }
        }
    }
    cout << ans << endl;
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
