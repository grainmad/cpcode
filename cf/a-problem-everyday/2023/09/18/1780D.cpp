
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

ll cur = 231232195;

ll cntbit(ll x) {
    ll cnt = 0;
    while (x) {
        cnt += x&1;
        x>>=1;
    }
    return cnt;
}

ll getn(ll x) {
    cur -= x;
    cout << cur << endl;
    return cntbit(cur);
}


void sol() {
    ll n;
    // n = getn(0);
    cin >> n;
    ll b = 0, p = n, d = 0;
    ll ans = 0;
    while (d < n) {
        cout << "- " << (1LL<<b+1) - (1LL<<b-d) << endl;
        p = n;
        // n = getn((1LL<<b+1) - (1LL<<b-d));
        cin >> n;
        if (n == -1) return ;
        d = n-(p-d)+1;
        b += d;
        // cout << "d: " << d << " p: " << p << " n: " << n << " b: " << b << endl;
        ans |= 1<<b;
    }
    cout << "! " << ans << endl;
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
