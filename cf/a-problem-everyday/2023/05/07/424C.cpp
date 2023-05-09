
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

// void sol() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     int ans = 0;
//     for (int& i : a)
//         cin >> i, ans ^= i;
//     vector<int> d(n + 5);
//     for (int i = 1; i <= n; i++) {
//         int o = n / i % 2;
//         if (n % i == 0) {
//             if (o) {  // [0, i-1]
//                 d[0]++;
//                 d[i]--;
//             }
//         } else {
//             if (o) {  // [0] and [n%i+1, i-1]
//                 d[0]++;
//                 d[1]--;
//                 d[n % i + 1]++;
//                 d[i]--;
//             } else {  // [1, n%i]
//                 d[1]++;
//                 d[n % i + 1]--;
//             }
//         }
//     }
//     int c = 0;
//     for (int i = 0; i <= n; i++) {
//         c += d[i];
//         if (c % 2)
//             ans ^= i;
//     }
//     cout << ans << "\n";
// }

void sol() {
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 1; i < n; i++) {
        f[i] = f[i - 1] ^ i;
    }
    int ans = 0;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
        ans ^= i;
    }
    for (int i = 1; i <= n; i++) {
        if (n / i % 2) {
            ans ^= f[i - 1];
        }
        ans ^= f[n % i];
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
