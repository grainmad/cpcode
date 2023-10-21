
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
    vector<int> a(n), b(n);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    vector<int> d;
    for (int x=30; x>=0; x--) {
        int a1=0, b1=0;
        for (int i=0; i<n; i++) {
            a1 += a[i]>>x&1;
            b1 += b[i]>>x&1;
        }
        if (a1 + b1 == n) d.push_back(x);
    }
    int ans = 0;
    while (1) {
        sort(a.begin(), a.end(), [&](auto x, auto y) {
            for (int i:d) {
                if ((x>>i&1) != (y>>i&1)) {
                    return (x>>i&1) < (y>>i&1);
                }
            }
            return false;
        });
        sort(b.begin(), b.end(), [&](auto x, auto y) {
            for (int i:d) {
                if ((x>>i&1) != (y>>i&1)) {
                    return (x>>i&1) > (y>>i&1);
                }
            }
            return false;
        });
        ans = a[0]^b[0];
        for (int i=1; i<n; i++) {
            ans &= a[i]^b[i];
        }
        int ok = 1;
        for (int i=0; i<d.size(); i++) {
            if (ans>>d[i]&1) continue;
            d.erase(d.begin()+i);
            ok = 0;
            break;
        }
        if (ok) break;
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
    // if (t == 10000)
    // for (int i=1; i<=t; i++) {
    //     int n;
    //     cin >> n;
    //     vector<int> a(n), b(n);
    //     for (auto& i:a) cin >> i;
    //     for (auto& i:b) cin >> i;
    //     if (13 == i) {
    //         cout << n << endl;
    //         for (auto i:a) cout << i << " "; cout << endl;
    //         for (auto i:b) cout << i << " "; cout << endl;
    //     }
    // }
    // else 
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}
