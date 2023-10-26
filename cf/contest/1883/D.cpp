#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    map<int, int> l, r;
    for (int i = 0; i < n; i++) {
        string opt;
        int a, b;
        cin >> opt >> a >> b;
        if (opt == "+") {
            int ok = 0;
            l[a]++;
            r[b]++;
        } else {
            if (--l[a] == 0)
                l.erase(a);
            if (--r[b] == 0)
                r.erase(b);
        }
        if (l.size() && r.size() && l.rbegin()->first > r.begin()->first)
            cout << "YES\n";
        else
            cout << "NO\n";
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