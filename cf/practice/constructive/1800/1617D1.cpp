#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    cout << "? 1 2 3" << endl;
    int p;
    cin >> p;
    vector<int> ans;
    for (int i = 1; i < n; i++) {
        cout << "? " << i + 1 << " " << (i + 1) % n + 1 << " "
             << (i + 2) % n + 1 << endl;
        int x;
        cin >> x;
        if (x == p)
            continue;
        ans.push_back(p ? (i + 2) % n + 1 : i);
        for (int j = 1; j <= n; j++) {
            if (j == i || j == (i + 2) % n + 1)
                continue;
            cout << "? " << i << " " << j << " " << (i + 2) % n + 1 << endl;
            cin >> x;
            if (x == 0)
                ans.push_back(j);
        }
        break;
    }
    cout << "! " << ans.size();
    for (int i : ans) {
        cout << " " << i;
    }
    cout << endl;
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