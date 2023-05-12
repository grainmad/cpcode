
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 10000005
// #define N 105
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
    vector<int> a(n, -1), b(n, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> fac;
        while (lpf[x] != 1) {
            if (fac.empty() || fac.back() != lpf[x])
                fac.push_back(lpf[x]);
            x /= lpf[x];
        }
        int mult = 1;
        for (int j : fac) {
            // cout << j << " ";
            mult *= j;
        }
        // cout << "\n";
        if (fac.size() > 1) {
            a[i] = fac[0];
            b[i] = mult / fac[0];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

/*
TLE O(n sqrt(n))
void sol() {
    int n;
    cin >> n;
    vector<int> a(n, -1), b(n, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> fac;
        for (int j = 2; j * j <= x; j++) {
            if (x % j)
                continue;
            fac.push_back(j);
            while (x % j == 0)
                x /= j;
        }
        if (x != 1) {
            fac.push_back(x);
        }
        int mult = 1;
        for (int j : fac) {
            // cout << j << " ";
            mult *= j;
        }
        // cout << "\n";
        if (fac.size() > 1) {
            a[i] = fac[0];
            b[i] = mult / fac[0];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}
*/
int main() {
    sieve();
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
