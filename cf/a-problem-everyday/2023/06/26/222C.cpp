
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
#define MAXN 10000007
using namespace std;

vector<int> p;
int lpf[MAXN];  // lpf[i] i的最小质因子
int ap[MAXN], bp[MAXN];

void least_prime_factor(int n) {  // 求n及以内的所有数的最小质因子
    for (int i = 2; i <= n; i++) {
        if (lpf[i] == 0) {
            p.push_back(i);
            lpf[i] = i;
        }
        for (int j = 0; 1LL * p[j] * i <= n; j++) {
            lpf[p[j] * i] = p[j];
            if (i % p[j] == 0)
                break;
        }
    }
    lpf[1] = 1;
    // for (int i = 1; i <= n; i++) {
    //     // cout << i << " " << lpf[i] << endl;
    //     cout << lpf[i] << " ";
    // }
    // cout << "\n";
}

void sol() {
    least_prime_factor(MAXN - 1);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& i : a) {
        cin >> i;
        int x = i;
        for (; lpf[x] != 1; x /= lpf[x]) {
            ap[lpf[x]]++;
        }
    }
    for (auto& i : b) {
        cin >> i;
        int x = i;
        for (; lpf[x] != 1; x /= lpf[x]) {
            bp[lpf[x]]++;
        }
    }
    for (auto i : p) {
        ap[i] = bp[i] = min(ap[i], bp[i]);
    }
    for (auto& i : a) {
        int x = i;
        for (; lpf[x] != 1; x /= lpf[x]) {
            if (ap[lpf[x]] > 0) {
                ap[lpf[x]]--;
                i /= lpf[x];
            }
        }
    }
    for (auto& i : b) {
        int x = i;
        for (; lpf[x] != 1; x /= lpf[x]) {
            if (bp[lpf[x]] > 0) {
                bp[lpf[x]]--;
                i /= lpf[x];
            }
        }
    }
    cout << n << " " << m << "\n";
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : b) {
        cout << i << " ";
    }
    cout << "\n";
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
