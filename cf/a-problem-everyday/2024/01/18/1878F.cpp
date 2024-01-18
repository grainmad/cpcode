
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n, q;
    cin >> n >> q;
    map<int,int> mp;
    auto sp = [&](int x) {
        for (int i=2; i*i<=x; i++) {
            while (x%i == 0) {
                x /= i;
                mp[i]++;
            }
        }
        if (x != 1) mp[x]++;
    };
    auto d = [&]() {
        int rt = 1;
        for (auto [i,j]:mp) {
            rt *= j+1;
        }
        return rt;
    };
    auto check = [&](int x) {
        for (int i=2; i*i<=x; i++) {
            if (x%i) continue;
            int c = 0;
            while (x%i == 0) {
                x /= i;
                c++;
            }
            if (!mp.count(i) || mp[i] < c) return false;
        }
        if (x != 1) {
            if (!mp.count(x)) return false;
        }
        return true;
    };
    sp(n);
    for (int i=0; i<q; i++) {
        int k, x;
        cin >> k;
        if (k == 1) {
            cin >> x;
            sp(x);
            if (check(d())) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            mp.clear();
            sp(n);
        }
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
