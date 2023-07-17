#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n, 0);
    ll sum = 0;
    multiset<int> st1, st2;
    for (int i = 0; i < n; i++) {
        if (i < k)
            st1.insert(0);
        else
            st2.insert(0);
    }
    auto adjust = [&]() {
        if (st2.empty())
            return;
        int x = *st1.begin();
        int y = *st2.rbegin();
        if (x < y) {
            st1.erase(st1.lower_bound(x));
            st2.erase(st2.lower_bound(y));
            st1.insert(y);
            st2.insert(x);
            sum -= x;
            sum += y;
        }
    };
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        if (st1.count(v[x])) {
            st1.erase(st1.lower_bound(v[x]));
            st1.insert(y);
            sum -= v[x];
            sum += y;
        } else {
            st2.erase(st2.lower_bound(v[x]));
            st2.insert(y);
        }
        adjust();
        v[x] = y;
        cout << sum << "\n";
    }
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