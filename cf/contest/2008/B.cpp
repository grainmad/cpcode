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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 1;
    while (l*l<n) l++;
    if (l*l>n) {
        cout << "No\n";
        return ;
    }
    int ok = 1;
    for (int i=0; i<l; i++) {
        if (s[i] == '0') ok =0;
    }
    for (int i=l; i<n-l; i+=l) {
        if (s[i] == '0' || s[i+l-1] == '0') ok = 0;
        for (int j=i+1; j<i+l-1; j++) {
            if (s[j] == '1') ok = 0;
        }
    }
    for (int i=n-l; i<n; i++) {
        if (s[i] == '0') ok =0;
    }
    cout << (ok?"Yes\n":"No\n");
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