
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

pair<int, int> f(int n) {  // len, cnt
    int len = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        int s = i + n, c = 0;
        while (s % 10 == 9) {
            s /= 10;
            c++;
        }
        if (c > len) {
            len = c;
            cnt = 1;
        } else if (c == len && c > 0) {
            cnt++;
        }
    }
    return {len, cnt};
}

void pt() {
    int n = 1000;
    vector<pair<int, int>> v;
    for (int i = 1; i < n; i++) {
        auto rt = f(i);
        v.push_back(rt);
        // cout << i << " " << rt.first << " " << rt.second << "\n";
    }
    vector<int> d(10);
    int p = 0;
    for (int i = 0; i < v.size(); i++) {
        p = max(v[i].first, p);
        if (v[i].first == p) {
            d[p] += v[i].second;
        }
        cout << i + 1 << " " << d[p] << "\n";
    }
}

void sol() {
    // pt();
    ll n, b = 5;
    cin >> n;
    if (n < 5) {
        cout << n * (n - 1) / 2 << "\n";
        return;
    }
    while (b * 10 <= n)
        b *= 10;
    ll ans = 0, c = 1, cur = b - 1;
    while (cur != n) {
        if (cur + 2 * b < n) {
            ans += 2 * b * c - 1;
            cur += 2 * b;
        } else {
            ans += (n - cur) * c;
            if (n >= cur + b)
                ans--;
            cur = n;
        }
        c++;
    }
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
