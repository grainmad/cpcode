
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
    string A, B;
    cin >> A >> B;
    int st[200];
    memset(st, -1, sizeof(st));
    function<int(int)> ufind = [&](int x) {
        return st[x] == -1 ? x : st[x] = ufind(st[x]);
    };
    for (int i = 0; i < n; i++) {
        if (A[i] > B[i]) {
            cout << "-1\n";
            return;
        }
        if (A[i] < B[i]) {
            int fa = ufind(A[i]), fb = ufind(B[i]);
            if (fa != fb) {
                st[fa] = fb;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 20; i++) {
        if (st[i + 'a'] != -1)
            ans++;
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
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}
