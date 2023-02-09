#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    string s(m, '0');
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        s[i] = '1';
        cout << "? " << s << endl;
        s[i] = '0';
        cin >> p[i];
    }
    vector<int> idx(m);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) { return p[x] < p[y]; });
    int span = 0;
    for (int i : idx) {
        s[i] = '1';
        cout << "? " << s << endl;
        int x;
        cin >> x;
        if (x == span + p[i]) {
            span = x;
        } else {  // 成环
            s[i] = '0';
        }
    }
    cout << "! " << span << endl;
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