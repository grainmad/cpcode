
#include <bits/stdc++.h>
// #define LOCAL
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 1000005
#define MOD 998244353
using namespace std;

vector<int> p;
int lpf[N];

void sieve() {
    lpf[1] = 1;
    for (int i = 2; i < N; i++) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            p.push_back(i);
        }
        for (int j = 0; p[j] * i < N; j++) {
            lpf[p[j] * i] = p[j];
            if (i % p[j] == 0) {
                break;
            }
        }
    }
    // for (int i : p) {
    //     cout << i << "\n";
    // }
    // for (int i = 1; i < N; i++) {
    //     cout << i << " " << lpf[i] << "\n";
    // }
}

void sol() {
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int fac = 1;
        while (lpf[x] != 1) {
            if (fac % lpf[x])
                fac *= lpf[x];
            else
                fac /= lpf[x];
            x /= lpf[x];
        }
        mp[fac]++;
    }
    int ans0 = 0, ans1 = 0, mx = 0;
    for (auto [i, j] : mp) {
        // cout << i << "--" << j << ", ";
        ans0 = max(ans0, j);
        if (i == 1 || j % 2 == 0)
            ans1 += j;
        else
            mx = max(mx, j);
    }
    ans1 = max(ans1, mx);
    // cout << "\n";
    int q;
    cin >> q;
    while (q--) {
        ll w;
        cin >> w;
        cout << (w ? ans1 : ans0) << "\n";
    }
}

int main() {
    sieve();
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
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
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: "
         << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}
