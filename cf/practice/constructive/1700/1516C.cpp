#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

int a[N];
int f[N];
int n;

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int s = accumulate(a + 1, a + n + 1, 0);
    if (s % 2) {
        cout << "0\n";
        return;
    }
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]]);
        }
    }
    if (!f[s / 2]) {
        cout << "0\n";
        return;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        c = gcd(c, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        a[i] /= c;
        if (a[i] % 2) {
            cout << "1\n" << i << "\n";
            return;
        }
    }
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