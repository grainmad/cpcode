#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

ll cnt(ll x) {
    ll rt = 0;
    while (x) {
        rt += x % 10;
        x /= 10;
    }
    return rt;
}

void sol() {
    ll n;
    cin >> n;
    ll a = n / 2, b = n - n / 2;
    if (abs(cnt(a) - cnt(b)) <= 1) {
        cout << a << " " << b << "\n";
        return;
    }
    string sa = to_string(a), sb = to_string(b);
    int sz = sa.size();
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    for (int i = 0, c = 0; i < sz; i++) {
        if (sa[i] == '9' && sb[i] == '0') {
            if (c % 2) {
                sa[i] = '4';
                sb[i] = '5';
            } else {
                sa[i] = '5';
                sb[i] = '4';
            }
            c++;
        }
    }
    reverse(sa.begin(), sa.end());
    reverse(sb.begin(), sb.end());
    cout << sa << " " << sb << "\n";
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