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
    vector<int> a(n + 1), c(n + 1), in(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        in[a[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    vector<int> p;
    ll ans = 0;
    while (q.size()) {
        int u = q.front();
        q.pop();
        p.push_back(u);
        if (--in[a[u]] == 0) {
            q.push(a[u]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in[i]) {
            vector<int> v;
            int j = i;
            while (in[j]) {
                v.push_back(j);
                in[j] = 0;
                j = a[j];
            }
            int mn = 0;
            for (int i = 0; i < v.size(); i++) {
                if (c[v[i]] < c[v[mn]]) {
                    mn = i;
                }
            }
            for (int i = 0; i < v.size(); i++) {
                p.push_back(v[(i + mn + 1) % v.size()]);
            }
        }
    }
    for (int i : p) {
        cout << i << " ";
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