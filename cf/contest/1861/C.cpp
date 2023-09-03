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
    int ok = 1;
    int cnt = 0;
    vector<int> ord(1, 1);
    for (char i : s) {
        if (i == '+') {
            cnt++;
            if (cnt >= 2)
                ord.push_back(ord.back() == -1 ? -1 : 0);
            else
                ord.push_back(1);
        }
        if (i == '-') {
            cnt--;
            int t = ord.back();
            ord.pop_back();
            if (t == 1)
                ord.back() = 1;
        }
        if (i == '0') {
            if (ord.back() == 1)
                ok = 0;
            else
                ord.back() = -1;
        }
        if (i == '1') {
            if (ord.back() == -1)
                ok = 0;
            else
                ord.back() = 1;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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