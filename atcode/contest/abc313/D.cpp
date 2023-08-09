#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 1005
#define MOD 998244353
using namespace std;

// vector<int> h = {0, 1, 0, 1, 0, 1, 1, 0, 0, 1};

int same[N];  // same[i] i与1是否一致

int query(vector<int>& a) {
    cout << "?";
    for (int i : a) {
        cout << " " << i;
    }
    cout << endl;
    int c = 0;
    // for (int i : a) {
    //     c += h[i - 1];
    // }
    cin >> c;
    return c % 2;
}

void sol() {
    int n, k;
    cin >> n >> k;
    vector<int> q(k);
    iota(q.begin(), q.end(), 1);
    int opt1 = query(q);
    for (int i = k + 1; i <= n; i++) {
        q[0] = i;
        if (query(q) == opt1) {
            same[i] = 1;
        }
    }
    if (k != 1) {
        q[0] = 1;
        for (int i = 2; i <= k; i++) {
            q[i - 1] = n;
            if (!((query(q) == opt1) ^ same[n])) {
                same[i] = 1;
            }
            q[i - 1] = i;
        }
    }
    same[1] = 1;
    int c = 0;
    // for (int i = 1; i <= n; i++) {
    //     cout << same[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= k; i++) {
        c += same[i];
    }
    // if (c % 2 == opt1) {  // 第一个是1
    //     cout << "!";
    //     for (int i = 1; i <= n; i++) {
    //         cout << " " << same[i];
    //     }
    //     cout << endl;
    // } else {
    //     cout << "!";
    //     for (int i = 1; i <= n; i++) {
    //         cout << " " << 1 - same[i];
    //     }
    //     cout << endl;
    // }
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << !((c % 2 == opt1) ^ same[i]);
    }
    cout << endl;
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