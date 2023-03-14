#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 150005
#define MOD 998244353
using namespace std;

map<int, vector<int>> mp;

int st[N];

void uf_init(int n) {
    for (int i = 0; i <= n; i++)
        st[i] = -1;
}
int uf_find(int x) {
    return st[x] < 0 ? x : st[x] = uf_find(st[x]);
}
void uf_union(int x, int y) {
    int fx = uf_find(x), fy = uf_find(y);
    if (fx != fy) {
        auto& q1 = mp[fx];
        auto& q2 = mp[fy];
        if (q1.size() > q2.size()) {
            while (q2.size())
                q1.push_back(q2.back()), q2.pop_back();
            mp.erase(fy);
            st[fy] = fx;
        } else {
            while (q1.size())
                q2.push_back(q1.back()), q1.pop_back();
            mp.erase(fx);
            st[fx] = fy;
        }
    }
}

void sol() {
    int n;
    cin >> n;
    uf_init(n);
    for (int i = 1; i <= n; i++)
        mp[i].push_back(i);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        uf_union(x, y);
    }
    for (int i : (mp.begin()->second)) {
        cout << i << " ";
    }
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