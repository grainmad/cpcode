
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for (auto& [i,j]:a) {
        cin >> i >> j;
    }
    vector<int> i1, i2;
    for (int i=0; i<n; i++) {
        if (a[i].first < a[i].second) i1.push_back(i);
        else i2.push_back(i);
    }
    if (i1.size() > i2.size()) {
        sort(i1.begin(), i1.end(), [&](int x, int y) {
            return a[x].second > a[y].second;
        });
        cout << i1.size() << "\n";
        for (int i:i1) {
            cout << i+1 << " ";
        } cout << "\n";
    } else {
        sort(i2.begin(), i2.end(), [&](int x, int y) {
            return a[x].first < a[y].first;
        });
        cout << i2.size() << "\n";
        for (int i:i2) {
            cout << i+1 << " ";
        } cout << "\n";
    }
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
