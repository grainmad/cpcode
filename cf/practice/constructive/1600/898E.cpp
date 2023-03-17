#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

ll s[N];

void sol() {
    for (ll i = 0; i < N; i++)
        s[i] = i * i;
    int n;
    cin >> n;
    vector<ll> sq, nsq;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll p = upper_bound(s, s + N, x) - s;
        ll dif = s[p] - x;
        if (p != 0)
            dif = min(dif, x - s[p - 1]);
        if (dif == 0)
            sq.push_back(x == 0 ? 2 : 1);
        else
            nsq.push_back(dif);
    }
    sort(sq.begin(), sq.end());
    sort(nsq.begin(), nsq.end());

    if (sq.size() >= n / 2) {
        cout << accumulate(sq.begin(), sq.begin() + sq.size() - n / 2, 0LL)
             << "\n";
    } else {
        cout << accumulate(nsq.begin(), nsq.begin() + n / 2 - sq.size(), 0LL)
             << "\n";
    }
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