#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll h, w, x1, y1, x2, y2;
    cin >> h >> w >> x1 >> y1 >> x2 >> y2;
    ll a = abs(x1 - x2) % 2;
    for (int i = 0; x1 < x2; i++) {
        if (i % 2) {  // b move
            if (a) {
                if (y1 < y2)
                    y2 = min(y2 + 1, w);
                else if (y1 > y2)
                    y2 = max(y2 - 1, 1LL);
                x2--;
            } else {
                if (y1 < y2)
                    y2--;
                else if (y1 > y2)
                    y2++;
                x2--;
            }
        } else {
            if (a) {
                if (y1 < y2)
                    y1++;
                else if (y1 > y2)
                    y1--;
                x1++;
            } else {
                if (y1 < y2)
                    y1 = max(y1 - 1, 1LL);
                else if (y1 > y2)
                    y1 = min(y1 + 1, w);
                x1++;
            }
        }
    }
    if (x1 == x2 && y1 == y2) {
        cout << (a ? "Alice\n" : "Bob\n");
    } else {
        cout << "Draw\n";
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