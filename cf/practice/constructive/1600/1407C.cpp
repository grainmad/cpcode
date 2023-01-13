#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

/*
a<b
a%b > b%a
get a

*/

void sol() {
    int n;
    cin >> n;
    vector<int> p(n + 1, n);
    int mx = 1;
    for (int i = 2; i <= n; i++) {
        int x, y;
        cout << "? " << mx << " " << i << endl;
        cin >> x;  // x = p[mx]%p[i]
        cout << "? " << i << " " << mx << endl;
        cin >> y;     // y = p[i]%p[mx]
        if (x > y) {  // p[mx] < p[i]
            p[mx] = x;
            mx = i;
        } else {  // p[mx] > p[i]
            p[i] = y;
        }
    }
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << p[i];
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