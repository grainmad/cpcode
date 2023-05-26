
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 200005
#define MOD 998244353
using namespace std;

vector<int> g[N];

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), c(N);
    for (int& i : a)
        cin >> i, c[i]++;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    vector<int> f(N);
    int ans = f[1] = c[1];
    for (int i : a) {
        for (int j : g[i])
            f[i] = max(f[i], c[i] + f[j]), ans = max(ans, f[i]);
    }
    cout << n - ans << "\n";
}

int main() {
    for (int i = 1; i < N; i++) {
        for (int j = 2 * i; j < N; j += i) {
            g[j].push_back(i);
        }
    }
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
