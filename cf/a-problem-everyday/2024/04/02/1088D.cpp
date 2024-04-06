
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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

ll ha = 10234132, hb = 1979843;
int cnt = 0;
int ask(ll c, ll d) {
    cnt++;
    cout << "? " << c << " " << d << endl;
    int rt;
    // if ((ha^c) == (hb^d)) rt = 1;
    // if ((ha^c) > (hb^d)) rt = 1;
    // if ((ha^c) < (hb^d)) rt = -1;
    cin >> rt;
    return rt;
}

void sol() {
    ll a = 0, b = 0;
    int p = ask(0, 0);
    for (int i=29; i>=0; i--) {
        ll x = 1<<i;
        if (p == 1) {
            int rt = ask(a|x, b|x);
            if (rt == -1) {
                a |= x;
                p = ask(a, b);
            } else {
                rt = ask(a|x, b);
                if (rt == -1) {
                    a |= x;
                    b |= x;
                }
            }
        } else if (p == -1) {
            int rt = ask(a|x, b|x);
            if (rt == 1) {
                b |= x;
                p = ask(a, b);
            } else {
                rt = ask(a, b|x);
                if (rt == 1) {
                    a |= x;
                    b |= x;
                }
            }
        } else {
            int rt = ask(a|x, b);
            if (rt == -1) {
                a |= x;
                b |= x;
            }
        }
    }
    cout << "! " << a << " " << b << endl;
    // cout << "cnt " << cnt << endl;
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
