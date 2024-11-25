#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& i:a) cin >> i;
    // cout << a << endl;
    map<int,vector<int>> r;
    for (int i:a) {
        r[i%k].push_back(i/k);
    }
    // cout << r << endl;
    int b = 0;
    for (auto& [i,j]:r) {
        for (int c:j) {
            b = max(c, b);
            if (c%2 != j[0]%2) {
                cout << "-1\n";
                return ;
            }
        }
    }
    map<ll,int> d;
    for (int i:a) {
        ll l;
        if (i/k%2 != b%2) {
            l = 1LL*(b-1)*k+i%k;
            d[l]++;
            d[l+k]--;
            l = 1LL*(b+1)*k+i%k;
            d[l]++;
            d[l+k]--;
        } else {
            l = 1LL*b*k+i%k;
            d[l]++;
            d[l+k]--;
        }
        // cout << i << " [" << l << ", " << l+k << ")" << endl;
    }
    // cout << d << endl;
    int ps = 0;
    for (auto [x, y]:d) {
        ps += y;
        if (ps == n) {
            cout << x << "\n";
            return ;
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