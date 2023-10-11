
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


ll h = 1231321;

ll ask(ll a, ll b) {
    cout << "? " << a << " " << b << endl;
    int rt;
    cin >> rt;
    // rt = gcd(h+a, h+b);
    return rt;
}

void sol() {
    ll r = 0;
    for (int i=0; i<30; i++) {
        ll rt = ask((1LL<<i)-r, (3LL<<i)-r);
        if (rt == (1<<i+1)) r |= 1LL<<i;
    }
    cout << "! " << r << endl;
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
