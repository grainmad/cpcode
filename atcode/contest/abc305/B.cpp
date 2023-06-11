#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int a[500];

void sol() {
    a['A'] = 0;
    a['B'] = 3;
    a['C'] = 4;
    a['D'] = 8;
    a['E'] = 9;
    a['F'] = 14;
    a['G'] = 23;
    string s1, s2;
    cin >> s1 >> s2;
    cout << abs(a[s1[0]] - a[s2[0]]) << "\n";
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