#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    if (k != 4) {
        int ans = k;
        for (int i : a) {
            ans = min(ans, (k - i % k) % k);
        }
        cout << ans << "\n";
    } else {
        int c2 = 0;
        for (int i : a) {
            if (i % 2 == 0) {
                while (i % 2 == 0) {
                    c2++;
                    i /= 2;
                }
            }
        }
        if (c2 >= 2) {
            cout << "0\n";
            return;
        }
        if (c2 == 1) {
            cout << "1\n";
            return;
        }
        int ans = 2;
        for (int i : a) {
            ans = min(ans, (k - i % k) % k);
        }
        cout << ans << "\n";
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