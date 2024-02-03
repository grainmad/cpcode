#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n,k,m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<int> c(k); 
    auto check = [&]() {
        for (int i:c) {
            if (i == 0) return false;
        }
        return true;
    };
    auto zero = [&]() {
        for (int& i:c) i = 0;
    };
    string t;
    for (char i:s) {
        c[i-'a'] = 1;
        if (check()) {
            t.push_back(i);
            zero();
        }
    }
    if (t.size() >= n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        cout << t;
        for (int i=0; i<k; i++) {
            if (c[i] == 0) {
                cout << char(i+'a');
                break;
            }
        }
        int sz = t.size();
        if (sz + 1 < n) cout << string(n-sz-1, 'a');
        cout << "\n";
    }
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