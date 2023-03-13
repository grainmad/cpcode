#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

int a[N], b[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (b[i] == 0)
            b[a[i]] = 1;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (int i : ans)
        cout << i << " ";
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