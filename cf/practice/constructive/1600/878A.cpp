#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    int o = 0, l = 1023, a = 1023, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "|")
            o |= x, l |= x;
        if (s == "^")
            o ^= x, l ^= x;
        if (s == "&")
            o &= x, l &= x;
    }
    for (int i = 0; i < 10; i++) {
        int x = o >> i & 1, y = l >> i & 1;
        if (x && y)
            b |= 1 << i;
        else if (!x && !y)
            a ^= 1 << i;
        else if (x && !y)
            c |= 1 << i;
    }
    cout << "3\n& " << a << "\n";
    cout << "| " << b << "\n";
    cout << "^ " << c << "\n";
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