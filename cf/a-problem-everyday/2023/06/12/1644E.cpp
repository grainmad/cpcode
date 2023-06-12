
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n;
    string s;
    cin >> n >> s;
    if (!count(s.begin(), s.end(), 'R') || !count(s.begin(), s.end(), 'D')) {
        cout << n << "\n";
        return;
    }
    int x1 = 1, y1 = 1, i = 0;
    while (i < s.size() && s[i] == s[0]) {
        if (s[i] == 'R') {
            y1++;
        } else {
            x1++;
        }
        i++;
    }
    int x2 = x1, y2 = y1, j = i;
    while (j < s.size()) {
        if (s[j] == 'R') {
            y2++;
        } else {
            x2++;
        }
        j++;
    }
    // cout << "x1 y1 " << x1 << " " << y1 << " x2 y2 " << x2 << " " << y2 <<
    // endl; cout << i << " " << j << "\n"; cout << "-- " << (x1 + y1 - 2) <<
    // endl; cout << "--- "
    //      << ((n - x1 + 1) * (n - y1 + 1) -
    //          ((y2 - y1 + 1) * (x2 - x1 + 1) - (j - i + 1)))
    //      << endl;
    cout << (x1 + y1 - 2) + ((n - x1 + 1) * (n - y1 + 1) -
                             ((y2 - y1 + 1) * (x2 - x1 + 1) - (j - i + 1)))
         << "\n";
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
