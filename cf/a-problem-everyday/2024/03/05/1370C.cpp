
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

int check(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n%2) return 1;
    if (n == (n&-n)) return 0;
    if ((n&-n) == 2) {
        n/=2;
        for (int i=3; i*i<=n; i+=2) {
            if (n%i == 0) return 1;
        }
        return 0;
    }
    return 1;
}

void sol() {
    int n;
    cin >> n; 
    if (check(n)) {
        cout << "Ashishgup" << "\n";
    } else {
        cout << "FastestFinger" << "\n";
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
