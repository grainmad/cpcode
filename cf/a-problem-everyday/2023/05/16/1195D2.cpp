
#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n;
    cin >> n;
    vector<string> a(n);
    vector<int> c(11);
    for (string& i : a) {
        cin >> i;
        reverse(i.begin(), i.end());
        c[i.size()]++;
    }
    // for (int i = 1; i < 12; i++) {
    //     cout << i << " " << c[i] << "\n";
    // }
    ll ans = 0;
    for (string i : a) {
        // cout << i << ": ";
        int sz = i.size();
        string low1, low2;
        for (int j = 0; j < 10; j++) {
            low1.push_back(j < sz ? i[j] : '0');
            low1.push_back('0');
            string t1 = low1 + i.substr(min(j + 1, sz));
            reverse(t1.begin(), t1.end());
            ll num1 = stoull(t1);
            // cout << j + 1 << "-- " << num1 << ", ";
            ans += num1 % MOD * c[j + 1] % MOD;
            ans %= MOD;

            low2.push_back('0');
            low2.push_back(j < sz ? i[j] : '0');
            string t2 = low2 + i.substr(min(j + 1, sz));
            reverse(t2.begin(), t2.end());
            ll num2 = stoull(t2);
            // cout << j + 1 << "-- " << num2 << ", ";
            ans += num2 % MOD * c[j + 1] % MOD;
            ans %= MOD;
        }
        // cout << "\n";
    }
    cout << ans << "\n";
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
