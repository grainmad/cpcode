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
template<class t> ostream& operator<<(ostream& os,const set<t>& v) {
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
    ll n, m;
    cin >> n >> m;
    set<int> X, Y, L, R;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        X.insert(x);
        Y.insert(y);
        L.insert(x-y);
        R.insert(x+y);
    }
    ll ans = (n-X.size())*(n-Y.size());
    for (int i:L) {
        set<int> cx;
        for (int j:X) {
            if (0 <= j-i && j-i < n) // y = x - (x-y)
                    cx.insert(j);
        }
        for (int j:Y) { 
            if (0 <= i+j && i+j < n) // x = x-y + y
                    cx.insert(i+j);
        }
        /*
            i 覆盖 n-|i|个点
            n = 4
            0 -1 -2 -3
            1  0 -1 -2
            2  1  0 -1
            3  2  1  0
        */ 
        ans -= n-abs(i) - int(cx.size());
    }
    for (int i:R) {
        set<int> cx;
        for (int j:X) {
            if (0 <= i-j && i-j < n) // y = x - (x+y)
                    cx.insert(j);
        }
        for (int j:Y) { 
            if (0 <= i-j && i-j < n) // x = x+y - y
                    cx.insert(i-j);
        }
        for (int j:L) { // (x+y + x-y) / 2
            if ((i+j)%2) continue;
            int x = (i+j)/2;
            int y = (i-j)/2;
            if (x<0 || x>=n || y<0 || y>=n) continue;
                cx.insert(x);
        }
        /*
            i 覆盖 n - |i - n + 1| 个点
            n = 4
            0  1  2  3
            1  2  3  4
            2  3  4  5
            3  4  5  6
        */ 
        ans -= n-abs(i-n+1) - int(cx.size());
    }
    cout << ans << "\n";
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