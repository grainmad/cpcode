#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}


void sol() {
    int n;
    cin >> n;
    vector<ll> a(n + 1), L(n + 2), R(n + 2), p(n + 1);
    iota(L.begin(), L.end(), 0);
    iota(R.begin(), R.end(), 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + a[i];
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1])
            L[i] = L[i - 1];
    }
    for (int i = n - 1; i > 0; i--) {
        if (a[i] == a[i + 1])
            R[i] = R[i + 1];
    }
    auto checkl = [&](int x) {
        if (x - 1 > 0 && a[x - 1] > a[x])
            return 1;
        int l = x - (L[x - 1] - 1), r = x;
        while (l < r) {
            int m = l + r >> 1;
            ll lb = max(1, x - m);
            if (p[x - 1] - p[lb - 1] > a[x]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (r == x)
            return N;
        return r;
    };
    auto checkr = [&](int x) {
        if (x + 1 <= n && a[x + 1] > a[x])
            return 1;
        int l = (R[x + 1] + 1) - x, r = n - x + 1;
        // cout << x << " " << l << " " << r << endl;
        while (l < r) {
            int m = l + r >> 1;
            ll rb = min(n, x + m);
            if (p[rb] - p[x] > a[x]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        if (r == n - x + 1)
            return N;
        return r;
    };
    for (int i = 1; i <= n; i++) {
        int ansl = checkl(i);
        int ansr = checkr(i);
        int ans = min(ansl, ansr);
        // cout << i << " " << ansl << " " << ansr << endl;
        if (ans == N)
            cout << "-1 ";
        else
            cout << ans << " ";
    }
    cout << "\n";
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