
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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

vector<int> h = {2,1};
int m = 1;

pair<int,int> ask(vector<int>& v) {
    cout << "?";
    for (int i:v) {
        cout << " " << i;
    }
    cout << endl;
    // vector<pair<int,int>> r;
    // for (int i:v) {
    //     r.emplace_back(i, h[i-1]);
    // }
    // sort(r.begin(), r.end(), [&](auto& x, auto& y) {
    //     return x.second < y.second;
    // });
    // return r[m-1];
    pair<int,int> rt;
    cin >> rt.first >> rt.second;
    return rt;
}


void sol() {
    int n = 2, k = 1;
    cin >> n >> k;
    vector<int> a(k);
    iota(a.begin(), a.end(), 1);
    int c = ask(a).second;
    int u=0, d=0;
    for (int i=0; i<k; i++) {
        int t = a[i];
        a[i] = k+1;
        auto [p, v] = ask(a);
        // cout << p << " " << v << endl;
        if (v < c) u++;
        else if (v > c) d++;
        a[i] = t;
    }
    if (u) {
        cout << "! " << k-u+1 << endl;
    } else {
        cout << "! " << d << endl;
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
