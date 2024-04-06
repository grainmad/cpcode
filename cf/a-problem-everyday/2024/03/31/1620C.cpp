
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
    ll n, k, x;
    cin >> n >> k >> x;
    x--;
    string s, ans;
    cin >> s;
    for (int i=n-1; i>=0; ) {
        int j = i;
        while (j>=0 && s[j] == '*') j--;
        if (j == i) {
            i--;
            ans.push_back('a');
        } else {
            ll c = ((i-j)*k+1);
            for (int t=0; t<x%c; t++) ans.push_back('b');
            x/=c;
            i = j;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
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
