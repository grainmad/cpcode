#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int, int>> st;
    while (m--) {
        int x, y;
        cin >> x >> y;
        st.insert({x, y});
    }
    int x = 0, y = 0;
    for (char i : s) {
        // cout << x << " " << y << " " << h << "\n";
        if (i == 'R') {
            if (--h < 0) {
                cout << "No\n";
                return;
            }
            if (st.count({x + 1, y}) && h < k)
                h = k, st.erase({x + 1, y});

            x += 1;
        }
        if (i == 'L') {
            if (--h < 0) {
                cout << "No\n";
                return;
            }
            if (st.count({x - 1, y}) && h < k)
                h = k, st.erase({x - 1, y});
            x -= 1;
        }
        if (i == 'U') {
            if (--h < 0) {
                cout << "No\n";
                return;
            }
            if (st.count({x, y + 1}) && h < k)
                h = k, st.erase({x, y + 1});
            y += 1;
        }
        if (i == 'D') {
            if (--h < 0) {
                cout << "No\n";
                return;
            }
            if (st.count({x, y - 1}) && h < k)
                h = k, st.erase({x, y - 1});
            y -= 1;
        }
    }
    cout << "Yes\n";
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