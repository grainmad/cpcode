
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
#define MAXN 1000005
#define SIGMA 11
using namespace std;

struct Trie {
    int tr[MAXN][SIGMA];  // 数组存储Trie树节点,下标起到指针作用
    int sz;               // Trie中当前节点个数

    Trie() { init(); }
    void init() {
        memset(tr[0], 0, sizeof(tr[0]));
        sz = 1;
    }
    // 插入
    void insert(vector<int>& s) {
        int len = s.size(), u = 0;
        for (int i = 0; i < len; i++) {
            if (tr[u][s[i]] == 0) {  // 不存在新开就一个节点
                tr[u][s[i]] = sz;
                memset(tr[sz], 0, sizeof(tr[sz]));
                sz++;
            }
            u = tr[u][s[i]];
        }
    }
    int query(vector<int>& s) {
        int len = s.size(), u = 0;
        for (int i = 0; i < len; i++) {
            if (tr[u][s[i]] == 0)
                return i;
            u = tr[u][s[i]];
        }
        return len;
    }
};

int a[N][11];
Trie trie;

void sol() {
    trie.init();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (auto& i : a) {
        for (auto& j : i)
            cin >> j, j--;
    }
    int ans = 0;
    for (auto& i : a) {
        vector<int> b(m);
        for (int j = 0; j < m; j++) {
            b[i[j]] = j;
        }
        trie.insert(b);
    }
    for (auto& i : a) {
        cout << trie.query(i) << " ";
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
