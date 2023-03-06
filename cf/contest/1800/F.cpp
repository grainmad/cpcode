#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM =
//             chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };

// void sol() {
//     // unordered_map<int, int> mp[26];

//     unordered_map<int, int, custom_hash> mp[26];
//     int mask = (1 << 26) - 1;
//     ll ans = 0;
//     int n;
//     string s;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> s;
//         int u = 0;
//         vector<int> c(26);
//         for (char j : s) {
//             u ^= 1 << j - 'a';
//             c[j - 'a']++;
//         }
//         for (int j = 0; j < 26; j++) {
//             if (c[j] == 0) {
//                 mp[j][u | (1 << j)]++;
//                 ans += mp[j][(u ^ mask) | (1 << j)];
//             }
//         }
//     }
//     cout << ans << "\n";
// }

int mp[1 << 26];

void sol() {
    int mask = (1 << 26) - 1;
    ll ans = 0;
    int n;
    cin >> n;
    string s;
    vector<vector<int>> c(n, vector<int>(26, 0));
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (char j : s) {
            b[i] ^= 1 << j - 'a';
            c[i][j - 'a']++;
        }
    }
    for (int _ = 0; _ < 26; _++) {
        for (int i = 0; i < n; i++) {
            if (c[i][_])
                continue;
            mp[b[i]]++;
            ans += mp[(b[i] ^ mask) ^ (1 << _)];
        }
        for (int i = 0; i < n; i++) {
            if (c[i][_])
                continue;
            mp[b[i]] = 0;
        }
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