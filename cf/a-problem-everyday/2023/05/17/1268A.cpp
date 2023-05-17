
#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    auto t = s;
    for (int i = 0; i < n; i++) {
        t[i] = s[i % k];
    }
    if (t >= s) {
        cout << n << "\n" << t;
        return;
    } else {
        for (int i = k - 1; i >= 0; i--) {
            if (t[i] == '9') {
                for (int j = i; j < n; j += k)
                    t[j] = '0';
            } else {
                for (int j = i; j < n; j += k)
                    t[j] = s[i] + 1;
                cout << n << "\n" << t;
                return;
            }
        }
    }
}

int main() {
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
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
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: "
         << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}
