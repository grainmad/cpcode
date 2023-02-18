#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int k;
    cin >> k;
    char u = 'a';
    while (k) {
        int a = 1;
        while (a * (a + 1) <= 2 * k)
            a++;
        for (int i = 0; i < a; i++) {
            cout << u;
        }
        k -= a * (a - 1) / 2;
        u++;
    }
    cout << u << "\n";
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