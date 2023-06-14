#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int g[5][5] = {{0, 0, 0, 0, 0},
               {0, 0, 1, 1, 0},
               {0, 1, 0, 1, 1},
               {0, 1, 1, 0, 1},
               {0, 0, 1, 1, 0}};

vector<int> getd(int ch) {
    vector<int> rt;
    for (int i = 1; i <= 5; i++) {
        if (g[ch][i] == 1)
            rt.push_back(i);
    }
    return rt;
}

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> st(1, 1);
    vector<int> vis(n + 1);
    vis[1] = 1;
    while (true) {
        int c;
        cin >> c;
        int ch = -1;
        for (int i = 0; i < c; i++) {
            int x;
            cin >> x;
            if (vis[x])
                continue;
            ch = x;
        }
        // for (int i : getd(st.back())) {
        //     if (vis[i])
        //         continue;
        //     ch = i;
        // }
        if (ch != -1) {
            vis[ch] = 1;
            st.push_back(ch);
        } else {
            st.pop_back();
        }
        cout << st.back() << endl;
        if (st.back() == n) {
            string s;
            cin >> s;
            break;
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