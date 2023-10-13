#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 1000005
#define MOD 998244353
using namespace std;

vector<int> p;
int lpf[N];

void sieve() {
    lpf[1] = 1;
    for (int i = 2; i < N; i++) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            p.push_back(i);
        }
        for (int j = 0; p[j] * i < N; j++) {
            lpf[p[j] * i] = p[j];
            if (i % p[j] == 0) {
                break;
            }
        }
    }
    // for (int i : p) {
    //     cout << i << "\n";
    // }
    // for (int i = 1; i < N; i++) {
    //     cout << i << " " << lpf[i] << "\n";
    // }
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    map<int, int> mp;
    for (int x : a) {
        while (lpf[x] != 1) {
            mp[lpf[x]]++;
            x /= lpf[x];
        }
    }
    for (auto [i, j] : mp) {
        if (j % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    sieve();
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