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
    vector<string> a(2);
    cin >> a[0] >> a[1];
    string s;
    s.push_back(a[0][0]);
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[0][i] == a[1][i - 1])
            cnt++, s.push_back(a[0][i]);
        if (a[0][i] < a[1][i - 1])
            cnt = 1, s.push_back(a[0][i]);
        if (a[0][i] > a[1][i - 1]) {
            for (int j = i - 1; j < n; j++) {
                s.push_back(a[1][j]);
            }
            break;
        }
    }
    if (s.size() != n + 1)
        s.push_back(a[1][n - 1]);
    cout << s << "\n";
    cout << cnt << "\n";
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