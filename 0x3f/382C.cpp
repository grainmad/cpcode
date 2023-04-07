#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    map<int, int> mp;
    for (int i = 1; i < n; i++) {
        mp[a[i] - a[i - 1]]++;
    }
    if (mp.size() == 0) {
        cout << "-1\n";
    } else if (mp.size() == 1) {
        auto [x, y] = *mp.begin();
        if (x == 0) {
            cout << "1\n" << a[0] << "\n";
        } else if (y == 1 && x % 2 == 0) {
            cout << "3\n"
                 << a[0] - x << " " << a[0] + x / 2 << " " << a[1] + x << "\n";
        } else {
            cout << "2\n" << a[0] - x << " " << a.back() + x << "\n";
        }
    } else if (mp.size() == 2) {
        auto [x1, y1] = *mp.begin();
        auto [x2, y2] = *mp.rbegin();
        if (x1 * 2 == x2 && y2 == 1) {
            cout << "1\n";
            for (int i = 1; i < n; i++) {
                if (a[i - 1] + x1 != a[i]) {
                    cout << a[i - 1] + x1 << "\n";
                    break;
                }
            }
        } else {
            cout << "0\n";
        }
    } else {
        cout << "0\n";
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