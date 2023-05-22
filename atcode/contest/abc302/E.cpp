#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, q;
    cin >> n >> q;
    vector<set<int>> st(n);
    int iso = n;
    for (int i = 0; i < q; i++) {
        int o, x, y;
        cin >> o;
        if (o == 1) {
            cin >> x >> y;
            x--, y--;
            st[x].insert(y);
            if (st[x].size() == 1)
                iso--;
            st[y].insert(x);
            if (st[y].size() == 1)
                iso--;
        } else {
            cin >> x;
            x--;
            for (int u : st[x]) {
                if (st[u].size()) {
                    st[u].erase(x);
                    if (st[u].size() == 0)
                        iso++;
                }
            }
            if (st[x].size()) {
                st[x].clear();
                iso++;
            }
        }
        cout << iso << "\n";
    }
}

int main() {
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
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
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: "
         << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}