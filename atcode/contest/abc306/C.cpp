#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> p(n), cnt(n), idx(n);
    for (int i = 0; i < 3 * n; i++) {
        int x;
        cin >> x;
        x--;
        if (++cnt[x] == 2) {
            p[x] = i;
        }
    }
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) { return p[x] < p[y]; });
    for (int i : idx) {
        cout << i + 1 << " ";
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