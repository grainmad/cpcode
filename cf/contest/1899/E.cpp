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
    int b = n - 1;
    priority_queue<int> q;
    for (int i = 0; i <= b; i++) {
        int p = a[b];
        while (i != b && a[i] <= a[b]) {
            if (a[b] > p) {
                cout << "-1\n";
                return;
            }
            p = a[b], b--;
        }
        if (i == b) {
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
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