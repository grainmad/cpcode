#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 1000000007
using namespace std;

int pos[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    ll ans = 1, l, r;
    l = r = pos[0];
    for (int i = 1; i < n; i++) {
        if (pos[i] < l)
            l = pos[i];
        else if (pos[i] > r)
            r = pos[i];
        else
            ans = ans * (r - l + 1 - i) % MOD;
    }
    cout << ans << "\n";
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