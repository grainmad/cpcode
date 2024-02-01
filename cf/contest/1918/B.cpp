#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i].first;
    }
    for (int i=1; i<=n; i++) {
        cin >> a[i].second;
    }
    sort(a.begin()+1, a.end());
    for (int i=1; i<=n; i++) {
        cout << a[i].first << " ";
    } cout << "\n";
    for (int i=1; i<=n; i++) {
        cout << a[i].second << " ";
    } cout << "\n";
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