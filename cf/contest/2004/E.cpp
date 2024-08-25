#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 10000005
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

int p[N], lpf[N];
int sz = 0;

void least_prime_factor(int n) {  // 求n及以内的所有数的最小质因子
    for (int i = 2; i <= n; i++) {
        if (lpf[i] == 0) {
            p[sz++] = i;
            lpf[i] = i;
        }
        for (int j = 0; 1LL * p[j] * i <= n; j++) {
            lpf[p[j] * i] = p[j];
            if (i % p[j] == 0)
                break;
        }
    }
    lpf[1] = 1;
    // for (int i = 0; i <= 20; i++) {
    //     // cout << i << " " << lpf[i] << endl;
    //     // cout << lpf[i] << " ";
    //     cout << p[i] << endl;
    // }
    // for (int i = 1; i <= 20; i++) {
    //     cout << i << " " << lpf[i] << endl;
        
    // }
    cout << "\n";
    
}

int sg(int n) {
    if (n%2) {
        if (n == 1) return 1;
        int pos = lower_bound(p, p+sz, lpf[n]) - p;
        return pos+1;
    } 
    return 0;
}

void sol() {
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int x;
        cin >> x;
        ans ^= sg(x);
    }
    cout << (ans == 0 ? "Bob":"Alice") << "\n";
}

int main() {
    least_prime_factor(N-1);
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