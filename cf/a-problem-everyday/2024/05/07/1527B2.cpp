
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto ans = [&](int u, int v) {
        // cout << u << " " << v << endl;
        if (u > v) cout << "BOB\n";
        else if (u < v) cout << "ALICE\n";
        else cout << "DRAW\n";
    };
    if (n%2) {
        int x = 0, y = 0, c = 0;
        if (s[n/2] == '0') c = 1;
        for (int i=0; i<n/2; i++) {
            if (s[i] != s[n-i-1]) x++;
            else if (s[i] == '0') y+=2;
        }
        // cout << "x: " << x << " y: " << y << " c: " << c << endl;
        int a = 0, b = 0;
        auto add = [&](int u, int v)->pair<int,int> { // 奇数回文，先手u，后手v
            if (c) {
                u += 1;
                v += y;
            } else {
                u += y;
                v += 0;
            }
            return pair<int,int>{u, v};
        };
        if (x == 0) {
            auto [u, v] = add(a, b);
            ans(u, v);
        } else {
            auto [v1, u1] = add(b+x-1, a+1);
            auto [u2, v2] = add(a, b+x);
            if (u1<v1) ans(u1, v1);
            else ans(u2, v2);
        }
    } else {
        int x = 0, y = 0, c = 0;
        if (s[n/2-1] == s[n/2] && s[n/2] == '0') c = 1;
        for (int i=0; i<n/2; i++) {
            if (s[i] != s[n-i-1]) x++;
        }
        for (int i=0; i<n/2-1; i++) {
            if (s[i] == s[n-i-1] && s[i] == '0') y+=2;
        }
        // cout << "x: " << x << " y: " << y << " c: " << c << endl;
        int a = 0, b = 0;
        auto add = [&](int u, int v)->pair<int,int> { // 偶数回文，先手u，后手v
            if (c) {
                if (y) {
                    u += y+1;
                    v += 1;
                } else {
                    u += 2;
                    v += 0;
                }
            } else {
                u += y;
                v += 0;
            }
            return pair<int,int>{u, v};
        };
        if (x == 0) {
            auto [u, v] = add(a, b);
            ans(u, v);
        } else {
            auto [v1, u1] = add(b+x-1, a+1);
            auto [u2, v2] = add(a, b+x);
            if (u1<v1) ans(u1, v1);
            else ans(u2, v2);
        }
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
