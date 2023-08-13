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
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    if (a[0] == a[n - 1]) {
        cout << "-1\n";
    } else {
        int cnt = 0;
        while (a[0] == a[cnt])
            cnt++;
        cout << cnt << " " << n - cnt << "\n";
        for (int i = 0; i < cnt; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
        for (int i = cnt; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
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