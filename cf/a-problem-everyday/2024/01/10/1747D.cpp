
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1), s(n+1);
    vector<ll> z(n+1);
    map<int,vector<int>> mpo,mpe;
    mpe[0].push_back(0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        z[i] = z[i-1] + a[i];
        s[i] = s[i-1]^a[i];
        if (i%2) mpo[s[i]].push_back(i);
        else mpe[s[i]].push_back(i);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (z[y] == z[x-1]) { // 全0无需修改
            cout << "0\n";
        } else if (s[y] != s[x-1]) { // 串异或为0
            cout << "-1\n";
        } else if ((y-x+1)%2) { // 奇数长度
            cout << "1\n";
        } else if (a[x] == 0 && s[y] == s[x] || a[y] == 0 && s[y-1] == s[x-1]) { // 偶数长度，存在0前缀或后缀
            cout << "1\n";
        } else {
            auto& t = (x%2?mpo[s[y]]:mpe[s[y]]);
            int l = upper_bound(t.begin(), t.end(), x-1) - t.begin();
            int r = lower_bound(t.begin(), t.end(), y) - t.begin();
            // cout << l << " " << r << endl;
            if (l<r) {
                cout << "2\n";
            } else {
                cout << "-1\n";
            }
        }
    }
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
