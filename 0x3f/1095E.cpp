#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 1000005
#define MOD 998244353
using namespace std;

char s[N];
int l[N], r[N], p[N];

void sol() {
    int n;
    cin >> n >> s + 1;
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == ')')
            continue;
        p[i] = pos;
        pos = i;
    }
    pos = n + 1;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '(')
            continue;
        p[i] = pos;
        pos = i;
    }
    for (int i = 1; i <= n; i++) {
        l[i] = l[i - 1];
        if (l[i] < 0)
            continue;
        if (s[i] == '(')
            l[i]++;
        else
            l[i]--;
    }
    for (int i = n; i >= 0; i--) {
        r[i] = r[i + 1];
        if (r[i] < 0)
            continue;
        if (s[i] == ')')
            r[i]++;
        else
            r[i]--;
    }
    // for (int i = 0; i <= n + 1; i++) {
    //     cout << i << " l:" << l[i] << " r:" << r[i] << " p:" << p[i] << endl;
    // }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = p[i];
        if (j == 0 || j == n + 1)
            continue;
        if (j < i) {
            if (l[j - 1] >= 0 && r[i + 1] >= 0 &&
                l[j - 1] == i - j - 1 + r[i + 1])
                ans++;
        } else {
            if (l[i - 1] >= 0 && r[j + 1] >= 0 &&
                r[j + 1] == j - i - 1 + l[i - 1])
                ans++;
        }
    }
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