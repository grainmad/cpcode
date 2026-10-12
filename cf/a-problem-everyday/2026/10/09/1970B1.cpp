
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

void sol() {
    int n;
    cin >> n; 
    vector<int> a(n);
    for (int& i:a) cin >> i;
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return a[x] < a[y];
    });
    vector<pair<int,int>> ans(n);
    vector<int> vis(n);
    if (a[idx[0]]) {
        for (int i=1; i<n; i++) {
            if (a[idx[i]] == a[idx[i-1]]) {
                swap(idx[0], idx[i-1]);
                swap(idx[1], idx[i]);
                break;
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (a[idx[i]] == 0) {
            ans[idx[i]] = {1, i+1};
            vis[idx[i]] = idx[i];
        } else if (i == 0) {
            // 无 0 时第 0 位是锚点：42-50 行已把同 a 伙伴换到位置 1，互指
            ans[idx[i]] = {1, i+1};
            vis[idx[i]] = idx[1];
        } else {
            if (a[idx[i]] <= i) {
                ans[idx[i]] = {ans[idx[i-a[idx[i]]]].first, i+1};
                vis[idx[i]] = idx[i-a[idx[i]]];
            } else {
                ans[idx[i]] = {a[idx[i]]-i+1, i+1};
                vis[idx[i]] = idx[0];
            }
        }
    }
    cout << "YES\n";
    for (auto [x, y] : ans) {
        cout << y << " " << x << "\n";
    }
    for (int i:vis) {
        cout << i+1 << ' ';
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
