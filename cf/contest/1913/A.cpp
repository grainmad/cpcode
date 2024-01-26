#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i=n-1; i>0; i--) {
        if (s[i] == '0') continue;
        if (stoi(s.substr(0, i)) < stoi(s.substr(i))) {
            cout << stoi(s.substr(0, i)) << " " << stoi(s.substr(i)) << "\n";
            return ;
        }
    }
    cout << "-1\n";
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