
#include <bits/stdc++.h>
// #define SINGLE_INPUT     // 多测时注释掉这行；单测时取消注释
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
    // 读入 -> 求解 -> 输出（cout << ... << "\n"）
    int n[2] = {0, 0};
    int r[2];
    for (int i=0; i<30; i++) {
        n[i%2] |= 1<<i;
    }
    for (int i=0; i<2; i++) {
        cout << n[i] << endl;
        cin >> r[i];
        r[i] -= 2*n[i];
    }
    
    int m;
    cout << "!" << endl;
    cin >> m;
    int ans = 2*m;
    vector<int> c(30);
    for (int i=0; i<30; i++) {
        c[i] = r[1-i%2] >> i & 3;
        if(!(m>>i&1))ans += (1<<i)*c[i];
    }
    cout << ans << endl;
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
