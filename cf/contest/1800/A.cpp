#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    int n;
    cin >> n >> s;
    for (char& i : s)
        if (islower(i))
            i = i - 'a' + 'A';
    // cout << s << endl;
    // cout << s.substr(0, unique(s.begin(), s.end()) - s.begin()) << endl;
    cout << (s.substr(0, unique(s.begin(), s.end()) - s.begin()) == "MEOW"
                 ? "YES\n"
                 : "NO\n");
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