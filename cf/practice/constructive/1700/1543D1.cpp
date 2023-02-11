#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k, r;
    cin >> n >> k;
    int p = 0;
    for (int i = 0; i < n; i++) {
        cout << (i ^ p) << endl;
        p = i;
        cin >> r;
        if (r == 1)
            return;
    }
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