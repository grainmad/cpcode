#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<string> g(h, string(w, '.'));
    int x=0, y=0, d=0;
    for (int i=0; i<n; i++) {
        // cout << i << " " << x << " " << y <<  " " << d << endl;
        if (g[x][y] == '.') {
            g[x][y] = '#';
            d = (d+3)%4;
        } else {
            g[x][y] = '.';
            d = (d+1)%4;
        }
        x = (x+(d-1)%2+h)%h;
        y = (y+(d-2)%2+w)%w;
    }
    for (auto& i:g) {
        cout << i << "\n";
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