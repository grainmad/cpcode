#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int a[N], b[N], p[N];

int pos(int u) {
    // cout << u << "\n";
    if (b[u]) {
        b[u]--;
        return u;
    }
    return p[u] = pos(p[u]);
}

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b[x]++;
        p[i] = (i + 1) % n;
    }
    for (int i = 0; i < n; i++) {
        cout << (pos(n - a[i]) + a[i]) % n << " ";
    }
    cout << "\n";
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