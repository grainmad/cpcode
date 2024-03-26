#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int c1 = count(s.begin(), s.end(), '1');
    int c0 = 0;
    vector<int> ok;
    if (c0 >= (0+1)/2 && c1 >= (n+1)/2) ok.push_back(0);
    for (int i=0; i<n; i++) {
        int lcnt = i+1, rcnt = n-lcnt;
        if (s[i] == '1') c1--;
        else c0++;
        // cout << c0 << " " << c1 << endl;
        if (c0 >= (lcnt+1)/2 && c1 >= (rcnt+1)/2) ok.push_back(lcnt);
    }
    // cout << ok << endl;
    int ans = 0, mn = 1e9;
    for (int i:ok) {
        if (mn>min(abs(n/2-i), abs((n+1)/2-i))) {
            mn = min(abs(n/2-i), abs((n+1)/2-i));
            ans = i;
        }
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