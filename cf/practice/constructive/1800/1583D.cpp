#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll nxt[N], vis[N], a[N];
int n;
int ta[N] = {0, 3, 2, 1, 5, 4}, tb[N];

int q(int p, int x) {
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        tb[i] = ta[i] + (p == i ? x : 3 - x);
        if (mp.count(tb[i]))
            return mp[tb[i]];
        mp[tb[i]] = i;
    }
    return 0;
}

void sol() {
    int x;
    cin >> n;
    // n = 5;
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cout << "?";
        for (int j = 1; j <= n; j++) {
            if (j == i)
                cout << " 2";
            else
                cout << " 1";
        }
        cout << endl;
        cin >> x;
        // x = q(i, 2);
        if (x < i) {  // a[x] = a[i] + 1
            nxt[i] = x;
        }
        cout << "?";
        for (int j = 1; j <= n; j++) {
            if (j == i)
                cout << " 1";
            else
                cout << " 2";
        }
        cout << endl;
        cin >> x;
        // x = q(i, 1);
        if (x < i) {  // a[x] + 1 = a[i]
            nxt[x] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        vis[nxt[i]] = 1;
    }
    int u = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            u = i;
            break;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ": " << nxt[i] << endl;
    // }
    for (int i = 1; i <= n; i++) {
        a[u] = i;
        u = nxt[u];
    }
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << a[i];
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