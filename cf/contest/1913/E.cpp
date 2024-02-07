#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long

#define MOD 998244353
using namespace std;

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

const int N = 5e3 + 5, M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int tot = 1, lnk[N], cur[N], ter[M], nxt[M], cap[M], cost[M], dis[N], ret;
bool vis[N];

void add(int u, int v, int w, int c) {
  ter[++tot] = v, nxt[tot] = lnk[u], lnk[u] = tot, cap[tot] = w, cost[tot] = c;
}

void addedge(int u, int v, int w, int c) { add(u, v, w, c), add(v, u, 0, -c); }

bool spfa(int s, int t) {
  memset(dis, 0x3f, sizeof(dis));
  memcpy(cur, lnk, sizeof(lnk));
  std::queue<int> q;
  q.push(s), dis[s] = 0, vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop(), vis[u] = 0;
    for (int i = lnk[u]; i; i = nxt[i]) {
      int v = ter[i];
      if (cap[i] && dis[v] > dis[u] + cost[i]) {
        dis[v] = dis[u] + cost[i];
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return dis[t] != INF;
}

int dfs(int u, int t, int flow) {
  if (u == t) return flow;
  vis[u] = 1;
  int ans = 0;
  for (int &i = cur[u]; i && ans < flow; i = nxt[i]) {
    int v = ter[i];
    if (!vis[v] && cap[i] && dis[v] == dis[u] + cost[i]) {
      int x = dfs(v, t, std::min(cap[i], flow - ans));
      if (x) ret += x * cost[i], cap[i] -= x, cap[i ^ 1] += x, ans += x;
    }
  }
  vis[u] = 0;
  return ans;
}

pair<int,int> mcmf(int s, int t) {
  int ans = 0;
  while (spfa(s, t)) {
    int x;
    while ((x = dfs(s, t, INF))) ans += x;
  }
  return {ans, ret};
}


void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m, 0));
    int c1 = 0;
    for (auto& i:g) {
        for (auto& j:i) {
            cin >> j;
            if (j) c1++;
        }
    }
    vector<int> a(n), b(m);
    for (auto& i:a) cin >> i;
    for (auto& i:b) cin >> i;
    if (accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0)) {
        cout << "-1\n";
        return ;
    }
    int S = m+n+5, T = n+m+6;
    vector<int> aid(n), bid(m);
    iota(aid.begin(), aid.end(), 1);
    iota(bid.begin(), bid.end(), n+1);
    for (int i=0; i<n; i++) {
        addedge(S, aid[i], a[i], 0);
    }
    for (int i=0; i<m; i++) {
        addedge(bid[i], T, b[i], 0);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (g[i][j]) {
                addedge(aid[i], bid[j], 1, -1);
            } else {
                addedge(aid[i], bid[j], 1, 1);
            }
        }
    }
    auto [mf, mc] = mcmf(S, T);
    if (mf != accumulate(a.begin(), a.end(), 0)) {
        cout << "-1\n";
    } else {
        cout << c1+mc << "\n";
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