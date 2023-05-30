
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 1000005
#define MOD 1000000007
using namespace std;

int a[N];
int f[N];

void sol() {
    f[0] = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, j;
        cin >> x;
        for (j = 1; j * j < x; j++) {
            if (x % j == 0)
                f[x / j] += f[x / j - 1], f[x / j] %= MOD;
        }
        if (j * j > x)
            j--;
        for (; j > 0; j--) {
            if (x % j == 0)
                f[j] += f[j - 1], f[j] %= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[i];
        ans %= MOD;
    }
    cout << ans << "\n";
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
