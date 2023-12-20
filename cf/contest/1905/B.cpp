#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> in(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        in[x]++;
        in[y]++;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 1)
            c++;
    }
    cout << (c + 1) / 2 << "\n";
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