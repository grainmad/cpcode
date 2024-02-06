
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
    int k;
    cin >> s >> k;
    int m = s.size();
    vector<int> c(10);
    string ans = "1" + string(m, '0');
    string pre;
    for (int i=0; i<m; pre.push_back(s[i]), c[s[i]-'0'] = 1, i++) {
        for (int j=9; j>s[i]-'0'; j--) {
            auto cc = c;
            cc[j] = 1;
            int ap = count(cc.begin(), cc.end(), 1);
            if (ap > k) continue;
            int mn = 0;
            if (ap==k) {
                while (cc[mn] == 0) mn++;
            }
            // cout << i << " " << string(1, char(s[i]+1)) << endl;
            ans = pre + char(j+'0') + string(max(0,m-1-i), char(mn+'0'));
        }
    }
    if (count(c.begin(), c.end(), 1) <= k) {
        ans = s;
        // cout << "adf" << endl;
    }
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
