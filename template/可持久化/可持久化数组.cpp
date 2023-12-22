#include <iostream>
using namespace std;

#define N 1000005
#define lc(x) tr[x].l
#define rc(x) tr[x].r
int n, m, a[N];
struct node {
    int l, r;
    int v;
} tr[N * 25];

// 初始2n个节点，n次修改，每次最多增加logn+1个节点，共n(logn+3)节点

int root[N], idx;

void build(int& x, int l, int r) {
    x = ++idx;
    if (l == r) {
        tr[x].v = a[l];
        return;
    }
    int m = l + r >> 1;
    build(lc(x), l, m);
    build(rc(x), m + 1, r);
}
void modify(int& x, int y, int l, int r, int pos, int v) {
    x = ++idx;
    tr[x] = tr[y];
    if (l == r) {
        tr[x].v = v;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        modify(lc(x), lc(y), l, mid, pos, v);
    else
        modify(rc(x), rc(y), mid + 1, r, pos, v);
}
int query(int x, int l, int r, int pos) {
    if (l == r)
        return tr[x].v;
    int mid = l + r >> 1;
    if (pos <= mid)
        return query(lc(x), l, mid, pos);
    else
        return query(rc(x), mid + 1, r, pos);
}
int main() {
    int ver, op, x, y;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    build(root[0], 1, n);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &ver, &op);
        if (op == 1) {
            scanf("%d%d", &x, &y);
            modify(root[i], root[ver], 1, n, x, y);
        } else {
            scanf("%d", &x);
            printf("%d\n", query(root[ver], 1, n, x));
            root[i] = root[ver];
        }
    }
}