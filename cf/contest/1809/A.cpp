#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (char i : s)
        mp[i]++;
    if (mp.size() == 1) {
        cout << "-1\n";
    } else if (mp.size() == 2) {
        if (mp.begin()->second == 2) {
            cout << "4\n";
        } else {
            cout << "6\n";
        }
    } else {
        cout << "4\n";
    }
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