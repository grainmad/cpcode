#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

int a[N], b[N], c[N];
void sol() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (count(a, a + n, 1) != 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            for (int j = 0; j < n; j++) {
                b[j] = a[(i + j) % n];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        g[b[i]].push_back(i);
    }
    int r = n;
    for (int i = 1; i <= n; i++) {
        while (g[i].size()) {
            c[g[i].back()] = r--;
            g[i].pop_back();
        }
    }
    // cout << "b ";
    // for (int i = 0; i < n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    // cout << "c ";
    // for (int i = 0; i < n; i++) {
    //     cout << c[i] << " ";
    // }
    // cout << endl;
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (st.size() && st.back() < c[i]) {
            st.pop_back();
        }
        st.push_back(c[i]);
        if (st.size() != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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