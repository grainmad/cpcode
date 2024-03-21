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


/*
    滚动哈希,窗口大小为n
    当前字符串长度为len, hash = s[0]*BASE^{len-1} + s[1]*BASE^{len-2} + ... + s[len-1]*BASE^{0}
    左边移除s[0], hash -= s[0]*BASE^{len-1}
    右边添加ch, hash =  hash*BASE + ch
*/ 
template<typename T>
struct SlideStr {
    ll hash, n, base, mod;
    queue<T> q;
    vector<ll> B;
    SlideStr(ll n, ll base = 173, ll mod = 998244353):hash(0), n(n), mod(mod), base(base), B(n+1) {
        B[0] = 1;
        for (int i = 1; i <= n; i++) 
            B[i] = B[i - 1] * base % mod;
    }
    bool del_l() {
        int len = q.size();
        if (len == 0) return false;
        hash = (hash - q.front()*B[len-1]%mod + mod)%mod;
        q.pop();
        return true;
    }
    bool add_r(T ch) {
        if (q.size() == n) return false;
        q.push(ch);
        hash = (hash*base%mod+ch)%mod;
        return true;
    }
    ll get_hash() {
        return hash;
    }
};


void sol() {
    // y.del_l(); y.add_r('a');
    // cout << x.get_hash() << " " << y.get_hash() << endl;

    string s;
    cin >> s;
    int n = s.size();

    for (int i=n/2*2; i>0; i-=2) {
        SlideStr<char> a1(n), b1(n), a2(n, 191, 1e9+7), b2(n, 191, 1e9+7);
        for (int j=0; j<i/2; j++) {
            if (s[j] == '?' || s[j+i/2] == '?') {
                a1.add_r('?');
                b1.add_r('?');
                a2.add_r('?');
                b2.add_r('?');
            } else {
                a1.add_r(s[j]);
                b1.add_r(s[j+i/2]);
                a2.add_r(s[j]);
                b2.add_r(s[j+i/2]);
            }
            
        }
        for (int j=i; j<=n; j++) {
            int l = j-i, m = j-i/2, r = j;
            // s[l,m) == s[m,r) ?
            if (a1.get_hash() == b1.get_hash() && a2.get_hash() == b2.get_hash()) {
                cout << i << "\n";
                return ;
            }
            if (r<n) {
                a1.del_l();
                b1.del_l();
                a2.del_l();
                b2.del_l();
                if (s[m] == '?' || s[r] == '?') {
                    a1.add_r('?');
                    b1.add_r('?');
                    a2.add_r('?');
                    b2.add_r('?');
                } else {
                    a1.add_r(s[m]);
                    b1.add_r(s[r]);
                    a2.add_r(s[m]);
                    b2.add_r(s[r]);
                }
            }
        }
    }
    cout << "0\n";
    
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