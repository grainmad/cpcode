#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 每个前缀[1,i]都构建一颗权值线段树
// 查区间[l,r]的第k小，只需将版本r和版本l-1的值做差，找到前缀和为k的下标t，则t就是第k小。

#define N 200005
#define lc(x) tr[x].l
#define rc(x) tr[x].r
struct node {
    int l, r, s;  // s:节点值域中有多少个数
} tr[N * 20];
// n(logn+3)

int root[N], idx;
int n, m, a[N];
vector<int> b;

void build(int& x, int l, int r) {
    x = ++idx;
    if (l == r)
        return;
    int m = l + r >> 1;
    build(lc(x), l, m);
    build(rc(x), m + 1, r);
}
void insert(int x, int& y, int l, int r, int k) {
    y = ++idx;
    tr[y] = tr[x];
    tr[y].s++;
    if (l == r)
        return;
    int m = l + r >> 1;
    if (k <= m)
        insert(lc(x), lc(y), l, m, k);
    else
        insert(rc(x), rc(y), m + 1, r, k);
}

int query(int x, int y, int l, int r, int k) {
    if (l == r)
        return l;
    int m = l + r >> 1;
    int s = tr[lc(y)].s - tr[lc(x)].s;
    if (k <= s)
        return query(lc(x), lc(y), l, m, k);
    else
        return query(rc(x), rc(y), m + 1, r, k - s);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int bn = b.size();

    build(root[0], 1, bn);
    for (int i = 1; i <= n; i++) {
        int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        insert(root[i - 1], root[i], 1, bn, id);
    }
    while (m--) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int id = query(root[l - 1], root[r], 1, bn, k) - 1;
        printf("%d\n", b[id]);
    }
    return 0;
}