#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define INF 0x3f3f3f3f
#define MOD 998244353
using namespace std;

void sol() {
    int n, k;
    string s, ans;
    int dif = INF;
    cin >> n >> k >> s;
    for (char i = '0'; i <= '9'; i++) {
        vector<int> d;
        for (int j = 0; j < n; j++) {
            d.push_back(abs(s[j] - i));
        }
        sort(d.begin(), d.end());
        vector<int> c(10);
        for (int j = 0; j < k; j++) {
            c[d[j]]++;
        }
        string t = s;
        int td = 0;
        for (int l = 0; l < n; l++) {
            if (s[l] > i && c[s[l] - i]) {
                c[s[l] - i]--;
                t[l] = i;
                td += s[l] - i;
            }
        }
        for (int l = n - 1; l >= 0; l--) {
            if (s[l] < i && c[i - s[l]]) {
                c[i - s[l]]--;
                t[l] = i;
                td += i - s[l];
            }
        }
        // cout << t << endl;
        if (td < dif || td == dif && t < ans) {
            ans = t;
            dif = td;
        }
    }
    cout << dif << endl;
    cout << ans << "\n";
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