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
    vector<int> c(30);
    for (int i=0; i<n; i++) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            c[v]++;
        } else {
            vector<int> u = c;
            int ok = 1;
            for (int i=29; i>=0; i--) {
                if (v>>i&1) {
                    int nd = 1;
                    for (int j=i; j>=0; j--) {
                        if (u[j]>=nd) {
                            u[j] -= nd;
                            nd = 0;
                            break;
                        }
                        nd -= u[j];
                        u[j] = 0;
                        nd *= 2;
                    }
                    if (nd != 0) {
                        ok = 0;
                        break;
                    }
                }
            }
            cout << (ok?"YES\n":"NO\n");
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