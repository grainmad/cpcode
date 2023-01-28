#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int check(string& s) {
    int rt = -1, n = s.size();
    char ch = '\0';
    for (int i = 0; i < n; i++) {
        if (i > 0 && s[i - 1] + 1 == s[i] && s[i] > ch) {
            ch = s[i];
            rt = i;
        }
        if (i + 1 < n && s[i + 1] + 1 == s[i] && s[i] > ch) {
            ch = s[i];
            rt = i;
        }
    }
    return rt;
}

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0, p;
    while ((p = check(s)) != -1) {
        s.erase(s.begin() + p);
        cnt++;
    }
    cout << cnt << "\n";
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