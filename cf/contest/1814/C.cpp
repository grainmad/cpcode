#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<int> r(n);
    for (int& i : r)
        cin >> i;
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) { return r[x] > r[y]; });
    // for (int i : idx)
    //     cout << i + 1 << "--";
    // cout << endl;
    int p = s1, q = s2;
    vector<int> l1, l2;
    for (int i : idx) {
        if (p < q) {
            l1.push_back(i + 1);
            p += s1;
        } else {
            l2.push_back(i + 1);
            q += s2;
        }
    }
    cout << l1.size();
    for (int i : l1)
        cout << " " << i;
    cout << "\n";
    cout << l2.size();
    for (int i : l2)
        cout << " " << i;
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