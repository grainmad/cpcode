#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
#define MAXN 1000005
#define SIGMA 26
using namespace std;
// 仅含小写英文字母
using namespace std;
struct Trie {
    int tr[MAXN][SIGMA];  // 数组存储Trie树节点,下标起到指针作用
    int val[MAXN];  // 若当前节点不是一个模式串的结尾则为0
    int sz;         // Trie中当前节点个数
    Trie() {
        memset(tr, 0, sizeof(tr));
        memset(val, 0, sizeof(val));
        sz = 1;
    }
    // 插入
    void insert(string& s) {
        int len = s.size(), u = 0;
        for (int i = 0; i < len; i++) {
            if (tr[u][s[i] - 'a'] == 0) {  // 不存在新开就一个节点
                tr[u][s[i] - 'a'] = sz;
                sz++;
            }
            u = tr[u][s[i] - 'a'];
            val[u]++;
        }
    }

    ll query(string& s) {
        ll rt = 0;
        int len = s.size(), u = 0;
        for (int i = 0; i < len; i++) {
            if (tr[u][s[i] - 'a'] == 0)
                return 2 * rt;
            u = tr[u][s[i] - 'a'];
            rt += val[u];
        }
        return 2 * rt;
    }
} trie;

void sol() {
    int n;
    cin >> n;
    ll sz = 0;
    vector<string> s(n);
    for (auto& i : s)
        cin >> i, sz += i.size();
    for (auto& i : s) {
        trie.insert(i);
    }
    // ll ans = 2 * sz * n;
    // for (auto i : s) {
    //     reverse(i.begin(), i.end());
    //     ans -= trie.query(i);
    // }
    ll ans = 0;
    for (auto i : s) {
        reverse(i.begin(), i.end());
        ll tans = (ll)i.size() * n + sz;
        ans += tans - trie.query(i);
    }

    cout << ans << "\n";
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
