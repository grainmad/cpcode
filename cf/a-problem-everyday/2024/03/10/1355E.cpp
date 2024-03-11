
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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
    int N, A, R, M;
    cin >> N >> A >> R >> M;
    vector<ll> h(N+1);
    for (int i=1; i<=N; i++) {
        cin >> h[i];
    }
    sort(h.begin()+1, h.end());
    vector<ll> ps(N+1);
    for (int i=1; i<=N; i++) {
        ps[i] = ps[i-1] + h[i];
    }
    // cout << h << endl;
    auto cal = [&](ll sp, ll m) {
        ll l = sp, r = N-sp;
        ll sl = ps[l], sr = ps[N]-ps[l];
        ll a = l*m-sl, b = sr-r*m;
        ll mn = A+R<M?0L:min(a, b);
        // cout << "sp " << sp << endl;
        // cout << "m " << m << endl;
        // cout << "l " << l << endl;
        // cout << "r " << r << endl;
        // cout << "sl " << sl << endl;
        // cout << "sr " << sr << endl;
        // cout << "a " << a << endl;
        // cout << "b " << b << endl;
        // cout << "mn " << mn << endl;
        // cout << "cal " << A*(a-mn) + R*(b-mn) + M*(mn) << endl;
        // cout << endl;
        return A*(a-mn) + R*(b-mn) + M*(mn);
    };
    ll ans = 1e18;
    for (int i=1; i<N; i++) {
        ll l = h[i], r = h[i+1], lans, rans;
        while (l<r) {
            ll lmid = l + (r-l)/3;
            ll rmid = r - (r-l)/3;
            lans = cal(i, lmid), rans = cal(i, rmid);
            if (lans <= rans) r = rmid-1;
            else l = lmid + 1;
        }
        // cout << "i: " << i << " ans: " << min(lans, rans) << endl;
        ans = min(ans, min(lans, rans));
    }
    cout << ans%((ll) 1e18) << "\n";
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
