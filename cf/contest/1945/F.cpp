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
    vector<int> a(n), b(n);
    for (auto& i:b) cin >> i;
    for (int i=n-1; i>=0; i--) {
        int x;
        cin >> x;
        a[i] = b[x-1];
    }
    priority_queue<int,vector<int>,greater<>> pq;
    ll ans = 0, c = 0;
    for (int i=0; i<n; i++) {
        pq.push(a[i]);
        ll r = n-i-1;
        while (r+1 < pq.size()) pq.pop();
        if (pq.size() == r+1 && pq.top()*(r+1) >= ans) {
            ans = pq.top()*(r+1);
            c = r+1;
        }
    }
    cout << ans << " " << c << "\n";
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