#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

int mp[N];
vector<int> g[N];

// 树状数组
ll BIT[N];
// ll xBIT[N];

void bit_add(int x, ll val) {
    for (int i = x; i < N; i += i & -i) {
        BIT[i] += val;
        // xBIT[i] += x*val;
        // 区间查询时 BIT[i] += val; xBIT[i] += x*val;
    }
}

ll bit_ps(int x) {
    ll rt = 0;
    for (int i = x; i > 0; i -= i & -i) {
        rt += BIT[i];
        // rt += x*BIT[i]-xBIT[i];
        // 区间查询时 rt += (x+1)*BIT[i]-xBIT[i];
    }
    return rt;
}

// 懒标记线段树实现区间覆盖
struct Seg {
    int l, r;
    ll val, tag;
} seg[N << 2];

void push_down(Seg& u, Seg& l, Seg& r) {
    if (u.tag != -1) {
        l.val = u.tag;
        l.tag = u.tag;
        r.val = u.tag;
        r.tag = u.tag;
        u.tag = -1;
    }
}

void seg_build(int id, int l, int r, int val) {
    seg[id].l = l;
    seg[id].r = r;
    seg[id].val = val;
    seg[id].tag = -1;
    if (l == r) {
        // cin >> seg[id].val;
        return;
    }
    int m = l + r >> 1;
    seg_build(id << 1, l, m, val);
    seg_build(id << 1 | 1, m + 1, r, val);
}

void seg_update(int id, int l, int r, ll val) {
    if (l <= seg[id].l && seg[id].r <= r) {
        seg[id].val = val;
        seg[id].tag = val;
        return;
    }
    push_down(seg[id], seg[id << 1], seg[id << 1 | 1]);
    int m = seg[id].l + seg[id].r >> 1;
    if (l <= m)
        seg_update(id << 1, l, r, val);
    if (m < r)
        seg_update(id << 1 | 1, l, r, val);
}

ll seg_query(int id, int p) {
    if (p <= seg[id].l && seg[id].r <= p) {
        return seg[id].val;
    }
    push_down(seg[id], seg[id << 1], seg[id << 1 | 1]);
    ll rt = -1;
    int m = seg[id].l + seg[id].r >> 1;
    if (p <= m)
        rt = seg_query(id << 1, p);
    if (m < p)
        rt = seg_query(id << 1 | 1, p);
    return rt;
}

void sol() {
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    s = '_' + s;
    vector<pair<int, int>> lr(m);
    for (auto& [i, j] : lr)
        cin >> i >> j;
    seg_build(1, 1, n, m);
    /*
        将输入的区间离线，逆序插入线段树，每次区间覆盖将第i个区间的值修改为i。
        这样越早出现的区间会覆盖后来的区间
    */
    for (int i = m - 1; i >= 0; i--) {
        seg_update(1, lr[i].first, lr[i].second, i);
    }
    /*
        将s中的索引重排，排序的规则是按照二元组(s中索引所属区间的标号小,索引）字典序由小到大排序。
        实现的方式可以是桶排序，由于区间标号的值的范围在0到m，可以设置m个桶。
        或者编写排序规则调用排序api
    */

    int rs = 0;  // 所有区间包含的点个数。
    for (int i = 1; i <= n; i++) {
        int v = seg_query(1, i);
        g[v].push_back(i);
        if (v != m)
            rs++;
    }
    // 桶排序
    int pos = 1;
    for (int i = 0; i <= m; i++) {
        for (int j : g[i]) {
            mp[j] = pos++;
        }
    }
    /*
        另一种排序方式，值小的排前面，值相同的下标小的排前面
        sort(idx.begin() + 1, idx.end(), [&](int x, int y) {
            if (v[x] == v[y])
                return x < y;
            return v[x] < v[y];
        });
        for (int i = 1; i <= n; i++) {
            mp[idx[i]] = i;
        }
    */
    /*
        我们将字符串s的每个下标i映射到mp[i]，然后将所有mp[i]用树状数组维护。这样可在logn内求出前缀和
        为什么要求出前缀和。
        假设字符串中共有one个1。
        我们求数组树状数组中前one个元素的前缀和为k，便可知我们还需要one-k个1填充达到字典序最大。
        但是这里还有一点需要注意，记rs为所有区间去重后覆盖的点数，意味着我们最多只需要查询前rs个数的前缀和。
    */
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            bit_add(mp[i], 1);
        }
    }
    int one = count(s.begin() + 1, s.end(), '1');
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        s[x] = 1 - (s[x] - '0') + '0';
        if (s[x] == '1') {
            one++;
            bit_add(mp[x], 1);
        } else {
            one--;
            bit_add(mp[x], -1);
        }
        cout << min(one, rs) - bit_ps(min(one, rs)) << "\n";
    }
}

// 这里还有一种用平衡树set，通过移除区间达到为索引排序的效果。
void sol2() {
    int n, m, q;
    cin >> n >> m >> q;
    string s;
    cin >> s;
    s = '_' + s;
    vector<pair<int, int>> lr(m);
    for (auto& [i, j] : lr)
        cin >> i >> j;
    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);
    int pos = 1;
    for (auto [l, r] : lr) {
        auto it = st.lower_bound(l);
        while (it != st.end() && *it <= r) {
            mp[*it] = pos++;
            st.erase(it++);
        }
    }
    for (int i : st)
        mp[i] = pos++;
    int rs = n - st.size();
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            bit_add(mp[i], 1);
        }
    }
    int one = count(s.begin() + 1, s.end(), '1');
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        s[x] = 1 - (s[x] - '0') + '0';
        if (s[x] == '1') {
            one++;
            bit_add(mp[x], 1);
        } else {
            one--;
            bit_add(mp[x], -1);
        }
        cout << min(one, rs) - bit_ps(min(one, rs)) << "\n";
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