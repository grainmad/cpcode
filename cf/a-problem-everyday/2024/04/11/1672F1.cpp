
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
    int n;
    cin >> n; 
    vector<int> a(n), c(n+1);
    for (int& i:a) cin >> i;
    vector<vector<int>> g(n+1);
    for (int i=0; i<n; i++) {
        g[++c[a[i]]].push_back(i);
    }
    vector<int> b(n);
    for (auto& i:g) {
        int sz  = i.size();
        sort(i.begin(), i.end(), [&](int x, int y) {
            return a[x] < a[y]; 
        });
        // cout << i << endl;
        for (int j=0; j<sz; j++) {
            b[i[(j+sz-1)%sz]] = a[i[j]];
            // cout << j << ": " << i[j] << ", " << a[i[j]] << endl;
        }
    }
    // cout << g << endl;
    // cout << b << endl;
    for (int i:b) {
        cout << i << " ";
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