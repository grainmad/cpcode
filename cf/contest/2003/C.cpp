#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> c(26);
    for (char i:s) {
        c[i-'a']++;
    }
    priority_queue<pair<int,char>> pq;
    for (int i=0; i<26; i++) {
        if (c[i]) {
            pq.emplace(c[i],  char(i+'a'));
            // cout << format("{} {}", (i == mxi ? (c[i]+1)/2 : c[i]),  char(i+'a')) << endl;
        }
    }
    string ans;
    while (pq.size()) {
        auto [m1, c1] = pq.top();
        pq.pop();
        if (pq.size()) {
            auto [m2, c2] = pq.top();
            pq.pop();
            ans.push_back(c1);
            ans.push_back(c2);
            if (m1>1) pq.emplace(m1-1, c1);
            if (m2>1) pq.emplace(m2-1, c2);
        } else {
            ans.push_back(c1);
            if (m1>1) pq.emplace(m1-1, c1);
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
