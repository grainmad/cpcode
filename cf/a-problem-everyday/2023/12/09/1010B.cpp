
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<int> p = {1, 0, 1, 0, 1, 0};
int x = 10;

int ask(int y, int t) {
    int rt = 0;
    if (y > x)
        rt = -1;
    if (y < x)
        rt = 1;
    return p[t % p.size()] ? rt : -rt;
}

void sol() {
    int m, n;
    // cin >> m >> n;
    m = 50, n = 6;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        int rt = ask(1, i);
        if (rt == 0) {
            return;
        }
        if (rt == 1)
            c[i] = 1;
    }
    int l = 1, r = m + 1;
    for (int i = n; i < 60; i++) {
        int m = l + r >> 1;
        int rt = ask(m, i);
        if (rt == 0) {
            return;
        }
        if (!c[i % n]) {
            rt = -rt;
        }
        if (rt == 1) {
            l = m + 1;
        } else {
            r = m;
        }
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
