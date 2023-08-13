
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

int mp[200];
string ch = "win";

void sol() {
    mp['w'] = 0;
    mp['i'] = 1;
    mp['n'] = 2;
    int n;
    cin >> n;
    vector<int> cnt[3][3][3];
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int c[3] = {0};
        for (int i : s)
            c[mp[i]]++;
        cnt[c[0]][c[1]][c[2]].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        int a[3] = {0}, b[3] = {0};
        a[i] = 3;
        b[(i + 1) % 3] = 3;
        while (cnt[a[0]][a[1]][a[2]].size() && cnt[b[0]][b[1]][b[2]].size()) {
            int x = cnt[a[0]][a[1]][a[2]].back(),
                y = cnt[b[0]][b[1]][b[2]].back();
            cout << x << " " << ch[i] << " " << y << " " << ch[(i + 1) % 3]
                 << "\n";
            a[i]--;
            b[(i + 1) % 3]++;
            cnt[a[0]][a[1]][a[2]];
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
