#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 5005
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;

int f[N][N];

void sol() {
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    int n;
    cin >> n;
    vector<int> p, s;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        (x ? p : s).push_back(i);
    }
    int psz = p.size(), ssz = s.size();
    // cout << psz << " " << ssz << endl;
    for (int i = 1; i <= ssz; i++)
        f[i][0] = 0;
    for (int i = 1; i <= ssz; i++) {
        for (int j = 1; j <= psz; j++) {
            f[i][j] =
                min(f[i - 1][j], f[i - 1][j - 1] + abs(p[j - 1] - s[i - 1]));
            // cout << "[" << i << "," << j << "]=" << f[i][j] << endl;
        }
    }

    // int ans = INF;
    // for (int i = psz; i <= ssz; i++)
    //     ans = min(ans, f[i][psz]);
    // cout << ans << "\n";
    cout << f[ssz][psz] << "\n";
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