
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
    string s;
    cin >> s;
    int n = s.size();
    int l = 0, r = 0, q = 0;
    for (auto i:s) {
        if (i == '(') l++;
        if (i == ')') r++;
        if (i == '?') q++;
    }
    int nl = n/2-l, nr = n/2-r;
    if (q < 2 || nl == 0 || nr == 0) {
        cout << "YES\n";
        return ;
    }
    for (int i=0,j=1; j<=nl&&i<n; i++) {
        if (s[i] == '?') {
            if (j == nl) s[i] = ')';
            else s[i] = '(';
            j++;
        }
    }
    for (int i=n-1,j=1; j<=nr&&i>=0; i--) {
        if (s[i] == '?') {
            if (j == nr) s[i] = '(';
            else s[i] = ')';
            j++;
        }
    }
    int c = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '(') c++;
        else c--;
        if (c < 0) {
            cout << "YES\n";
            return ;
        }
    }
    cout << "NO\n";
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
