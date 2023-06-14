
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 100005
#define MOD 998244353
using namespace std;

ll x[N], y[N];
ll dx[N], dy[N];
ll r[N], c[N];
ll R[N], C[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    for (int i = 1; i < n; i++) {
        dx[i] = x[i + 1] - x[i];
        dy[i] = y[i + 1] - y[i];
        // cout << i << " " << dx[i] << " " << dy[i] << "\n";
    }

    for (int i = 1; i < n; i++) {
        r[i] += r[i - 1] + i * dx[i];
        c[i] += c[i - 1] + i * dy[i];
        // cout << i << " " << r[i] << " " << c[i] << "\n";
    }
    R[1] = dx[1] * dx[1];
    C[1] = dy[1] * dy[1];
    for (int i = 2; i < n; i++) {
        R[i] =
            2 * R[i - 1] - R[i - 2] + i * dx[i] * dx[i] + 2 * r[i - 1] * dx[i];
        C[i] =
            2 * C[i - 1] - C[i - 2] + i * dy[i] * dy[i] + 2 * c[i - 1] * dy[i];
    }
    cout << R[n - 1] + C[n - 1] << "\n";
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
