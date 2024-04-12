
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
    string a, b, c;
    cin >> a >> b >> c;
    auto cnt01 = [](string& s)->pair<int,int> {
        int c0 = 0, c1 = 0;
        for (char i:s) {
            if (i == '0') c0++;
            else c1++;
        }
        return {c0, c1};
    };
    auto [a0, a1] = cnt01(a);
    auto [b0, b1] = cnt01(b);
    auto [c0, c1] = cnt01(c);
    auto gen = [&](string& x, string& y, char tag) {
        // cout << x << " " << y << " " << tag << endl;
        string ans;
        int p1=0, p2=0;
        for (int i=0; i<n; i++) {
            while (p1<2*n && x[p1] != tag) ans.push_back(x[p1++]);
            while (p2<2*n && y[p2] != tag) ans.push_back(y[p2++]);
            ans.push_back(tag);
            p1++;
            p2++;
        }
        while (p1<2*n) ans.push_back(x[p1++]);
        while (p2<2*n) ans.push_back(y[p2++]);
        return ans;
    };
    if ((a0>a1) == (b0>b1)) {
        cout << gen(a, b, a0>a1?'0':'1') << "\n";
    } else if ((a0>a1) == (c0>c1)) {
        cout << gen(a, c, a0>a1?'0':'1') << "\n";
    } else {
        cout << gen(b, c, b0>b1?'0':'1') << "\n";
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
