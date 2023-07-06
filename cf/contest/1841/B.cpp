#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> v;
    int a = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (v.empty()) {
            v.push_back(x);
            cout << "1";
        } else {
            if (a && x >= v.back()) {
                cout << "1";
                v.push_back(x);
            } else if (a && x <= v[0]) {
                cout << "1";
                a = 0;
                v.push_back(x);
            } else if (!a && v.back() <= x && x <= v[0]) {
                cout << "1";
                v.push_back(x);
            } else {
                cout << "0";
            }
        }
    }
    cout << "\n";
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