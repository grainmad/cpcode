
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    if (p == 1) {
        cout << "NO\n";
    }
    if (p == 2) {
        if (s == "a")
            cout << "b\n";
        else if (s == "ab")
            cout << "ba\n";
        else
            cout << "NO\n";
    }
    if (p < 3)
        return;
    for (int i = n - 1; i >= 0; i--) {
        for (char j = s[i] + 1; j < 'a' + p; j++) {
            if (i - 1 >= 0 && s[i - 1] == j)
                continue;
            if (i - 2 >= 0 && s[i - 2] == j)
                continue;
            s[i] = j;
            for (int k = i + 1; k < n; k++) {
                char c = 'a';
                while (k - 1 >= 0 && s[k - 1] == c ||
                       k - 2 >= 0 && s[k - 2] == c)
                    c++;
                s[k] = c;
            }
            cout << s << "\n";
            return;
        }
    }
    cout << "NO\n";
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
