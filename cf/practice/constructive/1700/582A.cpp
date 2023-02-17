#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n * n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> a, val;
    for (auto [i, j] : mp) {
        val.push_back(i);
    }
    sort(val.rbegin(), val.rend());
    for (int i : val) {
        int p = 0;
        for (int j : a) {
            if (j % i == 0)
                p++;
        }
        int x = (int)sqrt(mp[i] + p * p) - p;
        for (int j : a) {
            if (j % i != 0) {
                mp[gcd(i, j)] -= 2 * x;
            }
        }
        while (x--)
            a.push_back(i);
    }
    for (int i : a)
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