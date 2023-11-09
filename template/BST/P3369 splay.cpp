#include <iostream>
using namespace std;

#define ls(x) tr[x].s[0]
#define rs(x) tr[x].s[1]
const int N = 1100010, INF = (1 << 30) + 1;
struct node {
    int s[2];  // 左右儿子
    int p;     // 父亲
    int v;     // 节点权值
    int cnt;   // 权值出现次数
    int siz;   // 子树大小
    void init(int p1, int v1) {
        p = p1, v = v1;
        cnt = siz = 1;
    }
} tr[N];

int root;  // 根节点编号
int idx;   // 节点个数

void pushup(int x) {
    tr[x].siz = tr[ls(x)].siz + tr[rs(x)].siz + tr[x].cnt;
}

// 左/右旋 6个指针的断开重连
void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x;
    tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1];
    tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y;
    tr[y].p = x;
    pushup(y), pushup(x);
}

// 将x不断旋转至k的儿子，k为0则x变为根
void splay(int x, int k) {
    while (tr[x].p != k) {
        int y = tr[x].p, z = tr[y].p;
        if (z != k)  // 折转底，直转中
            (ls(y) == x) ^ (ls(z) == y) ? rotate(x) : rotate(y);
        rotate(x);
    }
    if (!k)
        root = x;
}

// 先二分查找，找到v则自增，否则添加新节点v（添加的位置必为叶子），并将v旋转至根
void insert(int v) {  // 插入
    int x = root, p = 0;
    while (x && tr[x].v != v)
        p = x, x = tr[x].s[v > tr[x].v];
    if (x)
        tr[x].cnt++;
    else {
        x = ++idx;
        if (p)
            tr[p].s[v > tr[p].v] = x;
        tr[x].init(p, v);
    }
    splay(x, 0);
}

// 二分找到值为v的节点，然后旋转至根。
// v不存在，返回 小于v的最大值 或 大于v的最小值 节点
void find(int v) {  // 找到v并转到根
    int x = root;
    while (tr[x].s[v > tr[x].v] && v != tr[x].v)
        x = tr[x].s[v > tr[x].v];
    splay(x, 0);
}

// find(v)，根节点值小于v，则根节点就是v的前驱
// 否则根左子树的最大值为前驱
int getpre(int v) {  // 前驱
    find(v);
    int x = root;
    if (tr[x].v < v)
        return x;
    x = ls(x);
    while (rs(x))
        x = rs(x);
    splay(x, 0);
    return x;
}

// find(v)，根节点值大于v，则根节点就是v的后继
// 否则根右子树的最小值为后继
int getsuc(int v) {  // 后继
    find(v);
    int x = root;
    if (tr[x].v > v)
        return x;
    x = rs(x);
    while (ls(x))
        x = ls(x);
    splay(x, 0);
    return x;
}

// 找到v的前驱和后继，让前驱成为根，后继成为根的右儿子
// 由于v的前驱后继唯一，所以此时v必为叶子节点。
void del(int v) {  // 删除
    int pre = getpre(v);
    int suc = getsuc(v);
    splay(pre, 0), splay(suc, pre);
    int del = tr[suc].s[0];
    if (tr[del].cnt > 1)
        tr[del].cnt--, splay(del, 0);
    else
        tr[suc].s[0] = 0, splay(suc, 0);
}

// 值为v在树中的排名，其左子树的大小就是排名（负无穷哨兵的存在）
int getrank(int v) {  // 排名
    insert(v);
    int res = tr[tr[root].s[0]].siz;
    del(v);
    return res;
}

// 获取排名为k的值，二分
int getval(int k) {  // 数值
    int x = root;
    while (true) {
        if (k <= tr[ls(x)].siz)  // 其必在左子树
            x = ls(x);
        else if (k <= tr[ls(x)].siz + tr[x].cnt)
            break;
        else
            k -= tr[ls(x)].siz + tr[x].cnt, x = rs(x);
    }
    splay(x, 0);
    return tr[x].v;
}
// 插入哨兵 insert(-INF), insert(INF)
// 插入，删除，查询节点值x排名，查询排名x的节点值，查询节点值x的前驱和后继节点值

int main() {
    insert(-INF);
    insert(INF);  // 哨兵
    int n, op, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &op, &x);
        if (op == 1)
            insert(x);
        else if (op == 2)
            del(x);
        else if (op == 3)
            printf("%d\n", getrank(x));
        else if (op == 4)
            printf("%d\n", getval(x + 1));
        else if (op == 5)
            printf("%d\n", tr[getpre(x)].v);
        else
            printf("%d\n", tr[getsuc(x)].v);
    }
    return 0;
}