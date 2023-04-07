#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

int a[N], b[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    if (n % 2 == 1 && a[n / 2] != b[n / 2]) {
        cout << "no\n";
        return;
    }
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n / 2; i++) {
        mp[{a[i], a[n - i - 1]}]++;
        mp[{a[n - i - 1], a[i]}]++;
    }
    for (int i = 0; i < n / 2; i++) {
        if (--mp[{b[i], b[n - i - 1]}] == 0)
            mp.erase({b[i], b[n - i - 1]});
        if (--mp[{b[n - i - 1], b[i]}] == 0)
            mp.erase({b[n - i - 1], b[i]});
    }
    cout << (mp.size() ? "no\n" : "yes\n");
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