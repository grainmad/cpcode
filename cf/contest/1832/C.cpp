#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll& i : a)
        cin >> i;
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() == 1) {
        cout << "1\n";
        return;
    }
    int c = 2;
    for (int i = 2; i < a.size(); i++) {
        if (a[i - 2] < a[i - 1] && a[i - 1] > a[i])
            c++;
        if (a[i - 2] > a[i - 1] && a[i - 1] < a[i])
            c++;
    }
    cout << c << "\n";
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