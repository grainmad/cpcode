
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
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    int a, b, k;
    cin >> a >> b >> k;
    string x(a+b, '0'), y(a+b, '0');
    x[0] = y[0] = '1';
    if (k == 0) {
        cout << "YES\n";
        for (int i=0; i<b; i++) {
            x[i] = y[i] = '1';
        }
        cout << x << "\n";
        cout << y << "\n";
    } else if (a>0 && b>1 && k <= a+b-2) {
        cout << "YES\n";
        x[a+b-1-k] = y[a+b-1] = '1';
        for (int i=0,r=b-2; r>0 && i<a+b; i++) {
            if (x[i] == '0' && y[i] == '0') {
                x[i] = y[i] = '1';
                r--;
            }
        }
        cout << x << "\n";
        cout << y << "\n";
    } else {
        cout << "NO\n";
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
