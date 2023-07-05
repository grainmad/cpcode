
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

// int t = 1212;

int q1() {
    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << i << " ";
    }
    cout << endl;
    // int rt = t ^ 56;
    int rt;
    cin >> rt;
    return rt;
}

int q2() {
    cout << "? ";
    for (int i = 1; i <= 100; i++) {
        cout << (i << 7) << " ";
    }
    cout << endl;
    // int rt = t ^ (37 << 7);
    int rt;
    cin >> rt;
    return rt;
}

void sol() {
    int x = q1(), y = q2();
    cout << "! " << (x >> 7 << 7) + y % (1 << 7) << endl;
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
