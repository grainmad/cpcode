#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
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
    map<ll,int> mp;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int smsk = 0, tmsk = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'W')
            smsk |= 1LL<<i*2;
    }
    smsk |= 2LL<<(n)*2;
    smsk |= 2LL<<(n+1)*2;
    mp[smsk] = 0;
    for (int i=0; i<n; i++) {
        if (t[i] == 'W') {
            tmsk |= 1LL<<i*2;
        }
    }
    tmsk |= 2LL<<(n)*2;
    tmsk |= 2LL<<(n+1)*2;
    auto shr = [](ll x, int r) {
        return x>>r*2&3;
    };

    queue<pair<ll,int>> q;
    q.emplace(smsk, 0);
    while (q.size()) {
        auto [x, y] = q.front();
        // cout << x << " " << y << endl;
        q.pop();
        if (x == tmsk) {
            cout << y << "\n";
            return ;
        }
        int p = 0;
        for (int i=1; i<n+2; i++) {
            ll u = shr(x, i-1), v = shr(x, i);
            if (u == 2 && v == 2) {
                p = i;
                break;
            }
        }

        for (int i=1; i<n+2; i++) {
            if (abs(i-p)<=1) continue;
            ll u = shr(x, i-1), v = shr(x, i);
            ll nx = x;
            nx ^= 2LL<<(p-1)*2;
            nx ^= 2LL<<p*2;
            nx ^= u<<(i-1)*2;
            nx ^= v<<(i)*2;

            nx ^= u<<(p-1)*2;
            nx ^= v<<p*2;
            nx ^= 2LL<<(i-1)*2;
            nx ^= 2LL<<(i)*2;
            if (!mp.count(nx)) {
                mp[nx] = y+1;
                q.emplace(nx, y+1);
            }
        }
    }
    cout << "-1\n";

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