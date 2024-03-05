
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

int isp(int x) {
    for (int i=2; i*i<=x; i++) {
        if (x%i == 0) return false;
    }
    return true;
}

void sol() {
    int n;
    cin >> n;
    int b = n/2;
    int p = n;
    while (!isp(p)) p++;
    cout << p << "\n";
    cout << "1 " << n << "\n";
    for (int i=2; i<=n; i++) {
        cout << i << " " << i-1 << "\n";
    }
    for (int i=1; i<=p-n; i++) {
        cout << i << " " << i+b << "\n";
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
