
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
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}
void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> vis(n+1);
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (q.size()) {
        int x = q.front(); q.pop();
        for (int y:g[x]) {
            if (vis[y]) continue;
            vis[y] = 3- vis[x];
            q.push(y);
        }
    }
    // cout << vis << endl;
    int aw = 0;
    for (int i=1; i<=n; i++) {
        for (int j:g[i]) {
            if (vis[i] == vis[j]) {
                aw = 1;
            }
        }
    }
    if (aw) {
        cout << "Alice" << endl;
        for (int i=0; i<n; i++) {
            cout << "1 2" << endl;
            int x, y;
            cin >> x >> y;
        }
    } else {
        cout << "Bob" << endl;
        int p1=1, p2=1;
        while (p1<=n && vis[p1] != 1) p1++;
        while (p2<=n && vis[p2] != 2) p2++;
        while (p1<=n || p2<=n) {
            int a, b;
            cin >> a >> b;
            if (a>b) swap(a, b);
            if (p1<=n && a == 1) {
                cout << p1 << " " << a << endl;
                p1++;
                while (p1<=n && vis[p1] != 1) p1++;
            } else if (p2<=n && b == 3) {
                cout << p2 << " " << b << endl;
                p2++;
                while (p2<=n && vis[p2] != 2) p2++;
            } else if (b==2) {
                cout << p2 << " " << b << endl;
                p2++;
                while (p2<=n && vis[p2] != 2) p2++;
            } else {
                cout << p1 << " " << a << endl;
                p1++;
                while (p1<=n && vis[p1] != 1) p1++;
            }
        }
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
