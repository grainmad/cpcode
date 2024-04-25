
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
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

const ll inf = 0x3f3f3f3f3f3f3f3f;

void sol() {
    int n;
    cin >> n;
    vector w(3, vector<int>(n));
    for (auto& i:w) {
        for (auto& j:i) {
            cin >> j;
        }
    }
    vector<vector<int>> g(n);
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int d1 = 0, d2 = 0;
    vector<int> pt;
    for (int i=0; i<n; i++) {
        if (g[i].size() == 1) d1++, pt.push_back(i);
        if (g[i].size() == 2) d2++;
    }
    if (d1 == 2 && d2 == n-2) {
        vector<int> s;
        function<void(int, int)> dfs = [&](int x, int fa) {
            s.push_back(x);
            for (int y:g[x]) {
                if (y == fa) continue;
                dfs(y, x);
            }
        };
        dfs(pt[0], -1);
        // cout << s << endl;
        auto check = [&](vector<int> a) {
            ll cnt = 0;
            for (int i=0; i<n; i++) {
                cnt += w[a[i%3]][s[i]];
            }
            return cnt;
        };
        vector<int> v = {0,1,2};
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    if (i == j || j == k || i == k) continue;
                    vector<int> vt = {i,j,k};
                    if (check(vt) < check(v)) {
                        v = vt;
                    }
                }
            }
        }
        cout << check(v) << "\n";
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            ans[s[i]] = v[i%3];
        }
        // cout << ans << endl;
        for (int i:ans) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    } else {
        cout << "-1\n";
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
