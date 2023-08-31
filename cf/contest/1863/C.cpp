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
    vector<int> a(n), vis(n + 1);
    for (int& i : a) {
        cin >> i;
        vis[i] = 1;
    }
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) {
            a.push_back(i);
            break;
        }
    }
    n++;
    for (int i = 0, b = n - k % n; i < n - 1; i++) {
        cout << a[(i + b) % n] << " ";
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