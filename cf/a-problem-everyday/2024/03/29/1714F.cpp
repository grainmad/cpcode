
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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

void sol() {
    int n, d12, d23, d13;
    cin >> n >> d12 >> d23 >> d13;
    int s = d12+d23+d13;
    if (s%2) {
        cout <<"NO\n";
        return ;
    }
    s/=2;
    int d[4] = {0, s-d23, s-d13, s-d12};
    if (d[1]<0 || d[2]<0 || d[3]<0 || d[1]+d[2]+d[3]+1>n) {
        cout << "NO\n";
        return ;
    }
    cout << "YES\n";
    int nd = 5;
    int c = 4;
    for (int i=1; i<=3; i++) {
        if (d[i] == 0) {
            nd = 4;
            c = i;
        }
    }
    // cout << nd << " -- " << c << endl;
    for (int j=1; j<=3; j++) {
        int pre = j;
        if (c == j) continue;
        for (int i=0; i<d[j]-1; i++) {
            cout << pre << " " << nd << "\n";
            pre = nd;
            nd++;
        }
        cout << pre << " " << c << "\n";
    }
    while (nd <= n) {
        cout << "1 " << nd << "\n";
        nd++;
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
