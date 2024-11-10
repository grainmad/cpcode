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
    vector<ll> a(n);
    for (auto& i:a) cin >> i;
    vector<int> cur(n);
    iota(cur.begin(), cur.end(), 0);
    vector<pair<int,int>> ans;
    cout << "YES\n";
    for (int i=1; i<n; i++) {
        vector<int> mod(n-i);
        int p = -1;
        for (int j:cur) {
            if (++mod[a[j]%(n-i)] == 2) p = a[j]%(n-i);
        }
        // cout << mod << endl;
        vector<int> s;
        for (int j:cur) {
            if (p == a[j]%(n-i) && s.size() < 2) {
                s.push_back(j);
            }
        }
        // cout << s[0]+1 << " " << s[1]+1 << "\n";
        ans.emplace_back(s[0]+1, s[1]+1);
        assert(abs(a[s[0]] - a[s[1]])%(n-i) == 0);
        cur.erase(find(cur.begin(), cur.end(), s[0]));
    }
    reverse(ans.begin(), ans.end());
    for (auto& [x, y]:ans) {
        cout << x << " " << y << "\n";
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