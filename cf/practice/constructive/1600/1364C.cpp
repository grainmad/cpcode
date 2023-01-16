#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), b(n, -1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int mex = 0, cnt = 0, p = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mex)
            cnt++;
        else {
            if (a[i] - mex - 1 > cnt) {
                cout << "-1\n";
                return;
            }
            cnt -= a[i] - mex - 1;
            b[i] = mex;
            for (int j = mex + 1; j < a[i]; j++) {
                while (b[p] != -1)
                    p++;
                b[p] = j;
            }
            mex = a[i];
        }
    }
    for (int i = 1; i <= cnt; i++) {
        while (b[p] != -1)
            p++;
        b[p] = mex + i;
    }
    for (int i : b)
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