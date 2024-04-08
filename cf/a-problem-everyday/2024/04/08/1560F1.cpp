
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    ll k;
    string s;
    cin >> s >> k;
    int n = s.size();
    string ans = "1"+string(n, '0');
    vector<int> c(10);
    string pre;
    for (int i=0; i<n; i++) {
        for (int j=9; j>s[i]-'0'; j--) {
            auto t = c;
            t[j] = 1;
            int u = count(t.begin(), t.end(), 1);
            if (u > k) continue;
            int mn = 0;
            if (u == k) {
                while (t[mn] == 0) mn++;
            }
            string x = pre+char(j+'0')+string(n-i-1, char(mn+'0'));
            // cout << x << endl;
            ans = x;
        }
        pre.push_back(s[i]);
        c[s[i]-'0'] = 1;
    }
    if (count(c.begin(), c.end(), 1) <= k) {
        ans = s;
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
