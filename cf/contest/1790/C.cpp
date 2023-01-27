#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> v(n + 1), a;
    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        v[x]++;
        a.push_back(x);
    }
    int p = 0;
    for (int i = 1; i <= n; i++) {
        if (!v[i])
            p = i;
    }
    set<int> st;
    for (int i = 0; i < n - 1; i++) {
        bool ok = true;
        for (int j = 0; j < n - 1; j++) {
            int x;
            cin >> x;
            if (x == p)
                ok = false;
            if (ok) {
                st.insert(x);
            }
        }
    }
    a.insert(a.begin() + st.size(), p);
    for (int i : a)
        cout << i << " ";
    cout << "\n";
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