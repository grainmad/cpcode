
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
    vector<pair<int,int>> p(n-1);
    vector<vector<pair<int,int>>> g(n);
    vector<int> d(n);
    int pos = 1;
    for (auto& [x,y]:p) {
        cin >> x >> y;
        x--;
        y--;
        g[x].emplace_back(y, pos);
        g[y].emplace_back(x, pos);
        d[x]++;
        d[y]++;
        pos++;
    }
    // cout << d << endl;
    vector<int> fa(n, -1);
    function<int(int)> ufind = [&](int x) {
        return fa[x] < 0 ? x : ufind(fa[x]);
    };
    queue<int> q;
    for (int i=0; i<n; i++) {
        if (d[i] == 1) {
            q.push(i);
        }
    }
    vector<int> ans;
    vector<int> tp;
    while (q.size()) {
        auto x = q.front();
        q.pop();
        tp.push_back(x);
        for (auto [y, p]:g[x]) {
            --d[y];
            if (d[y] >= 1) {
                int fx = ufind(x), fy = ufind(y);
                // cout << x << " -- " << y << endl;
                // cout << fa[fx] << " -- " << fa[fy] << endl; 
                assert(fx != fy);
                if (fa[fx] + fa[fy] < -3) {
                    ans.push_back(p);
                } else {
                    fa[fx] += fa[fy];
                    fa[fy] = fx;
                }
            }
            if (d[y] == 1) {
                q.push(y);
            }
        }
    }
    if (tp.size()>2) {
        int fx = ufind(tp[n-2]), fy = ufind(tp[n-1]);
        assert(fx != fy);
        if (fa[fx] + fa[fy] < -3) {
            for (int i=0; i<n-1; i++) {
                auto [x, y] = p[i];
                if (x == tp[n-2] && y == tp[n-1] || y == tp[n-2] && x == tp[n-1]) {
                    ans.push_back(i+1);
                    break;
                }
            }
        } else {
            fa[fx] += fa[fy];
            fa[fy] = fx;
        }
    }
    for (int i=0; i<n; i++) {
        // cout << i << " " << ufind(i) << " " << fa[ufind(i)] << endl;
        if (fa[ufind(i)] != -3) {
            cout << "-1\n";
            return ;
        }
    }
    // cout << fa << endl;
    cout << ans.size() << "\n";
    for (auto i:ans) {
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
