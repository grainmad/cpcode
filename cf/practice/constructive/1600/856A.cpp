#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 1000001
#define MOD 998244353
using namespace std;

int fb[N];

void sol() {
    memset(fb, 0, sizeof(fb));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    sort(a.begin(), a.end());
    cout << "YES\n";
    for (int i = 0, p = 1; i < n; i++) {
        while (fb[p])
            p++;
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                fb[p + a[k] - a[j]] = 1;
            }
        }
        cout << p << " ";
        p++;
    }
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