
#include <bits/stdc++.h>
#define SINGLE_INPUT
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
template<class t> ostream& operator<<(ostream& os,const set<t>& v) {
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
    int n, m;
    cin >> n >> m;
    vector g(n+1, vector<int>());
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    set<int> st1, st2, st3;
    for (int i=1; i<=n; i++) st1.insert(i);
    for (int i=1; i<=n; i++) {
        if (st1.count(i))
        for (int j:g[i]) {
            if (st1.count(j)) st2.insert(j), st1.erase(j);
        }
    }
    for (int i=1; i<=n; i++) {
        if (st2.count(i))
        for (int j:g[i]) {
            if (st2.count(j)) st3.insert(j), st2.erase(j);
        }
    }
    for (int i:st3) {
        for (int j:g[i]) {
            if (st3.count(j)) {
                cout << "-1\n";
                return ;
            }
        }
    }
    if (st2.empty() || st3.empty()) {
        cout << "-1\n";
        return ;
    }
    int sz1 = st1.size(), sz2 = st2.size(), sz3 = st3.size();
    for (int i:st1) {
        if (g[i].size() != sz2+sz3) {
            cout << "-1\n";
            return ;
        }
    }
    for (int i:st2) {
        if (g[i].size() != sz1+sz3) {
            cout << "-1\n";
            return ;
        }
    }
    for (int i:st3) {
        if (g[i].size() != sz2+sz1) {
            cout << "-1\n";
            return ;
        }
    }
    // cout << st1 << endl;
    // cout << st2 << endl;
    // cout << st3 << endl;
    
    vector<int> v(n+1);
    iota(v.begin(), v.end(), 0);
    for (int i:st1) v[i] = 1;
    for (int i:st2) v[i] = 2;
    for (int i:st3) v[i] = 3;
    for (int i=1; i<=n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

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
