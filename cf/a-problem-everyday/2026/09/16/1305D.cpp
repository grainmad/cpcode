
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
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}
int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int z;
    cin >> z;
    return z;
}
void sol() {
    int n;
    cin >> n;
    vector<int> de(n+1);
    vector<vector<int>> g(n+1, vector<int>());
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        de[x]++;
        de[y]++;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    set<int> leaf;
    for (int i=1; i<=n; i++) {
        if (de[i] == 1) leaf.insert(i);
    }
    while (leaf.size()>1) {
        int x = *leaf.begin();
        leaf.erase(x);
        int y = *leaf.begin();
        leaf.erase(y);
        int z = ask(x, y);
        if (z == x || z == y) {
            leaf.clear();
            leaf.insert(z);
        } else {
            for (int i:g[x]) {
                if (--de[i] == 1) leaf.insert(i);
            }
            for (int i:g[y]) {
                if (--de[i] == 1) leaf.insert(i);
            }
        }
    }
    cout << "! " << *leaf.begin() << endl;
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
