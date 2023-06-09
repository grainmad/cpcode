#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    string s[2];
    cin >> s[0] >> s[1];
    int t, q;
    cin >> t >> q;
    int dif = 0;
    for (int i = 0; i < s[0].size(); i++) {
        dif += (s[0][i] != s[1][i]);
    }
    deque<pair<int, int>> dq;
    for (int i = 0; i < q; i++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int pos;
            cin >> pos;
            pos--;
            dq.emplace_back(i, pos);
            if (s[0][pos] != s[1][pos])
                dif--;
        } else if (opt == 2) {
            int w1, p1, w2, p2;
            cin >> w1 >> p1 >> w2 >> p2;
            p1--;
            p2--;
            w1--;
            w2--;
            if (p1 == p2) {
                swap(s[w1][p1], s[w2][p1]);
            } else {
                int d1 = (s[0][p1] != s[1][p1]);
                int d2 = (s[0][p2] != s[1][p2]);
                swap(s[w1][p1], s[w2][p2]);
                int d3 = (s[0][p1] != s[1][p1]);
                int d4 = (s[0][p2] != s[1][p2]);
                dif += d3 - d1;
                dif += d4 - d2;
            }

        } else {
            while (dq.size() && dq.front().first + t <= i) {
                int pp = dq.front().second;
                if (s[0][pp] != s[1][pp])
                    dif++;
                dq.pop_front();
            }
            cout << (dif == 0 ? "YES\n" : "NO\n");
        }
        while (dq.size() && dq.front().first + t <= i) {
            int pp = dq.front().second;
            if (s[1][pp] != s[0][pp])
                dif++;
            dq.pop_front();
        }
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