#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
using point = array<ll, 3>;

ll cross(point p, point q, point o) {  // op 叉乘 oq
    ll x1 = p[0] - o[0];
    ll y1 = p[1] - o[1];
    ll x2 = q[0] - o[0];
    ll y2 = q[1] - o[1];
    return x1 * y2 - y1 * x2;
}
ll mult(point p, point q, point o) {  // op 点乘 oq
    ll x1 = p[0] - o[0];
    ll y1 = p[1] - o[1];
    ll x2 = q[0] - o[0];
    ll y2 = q[1] - o[1];
    return x1 * x2 + y1 * y2;
}

// pq 与 r 的关系， r在pq左侧返回2，r在pq右侧返回0，r在pq上返回1
int check(point p, point q, point r) {
    ll c = cross(q, r, p);  // 向量pq 与 向量pr的叉乘为正，则r在pq左侧
    if (c)
        return c > 0 ? 2 : 0;
    ll i = mult(q, r, p);
    ll d = mult(q, q, p);
    return 0 <= i &&
           i <=
               d;  // 对于pq，pr都平行于扫描线，我们需要判断r在pq上的投影是否超出|pq|
}

int main() {
    int n;
    cin >> n;
    vector<point> p(n);
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        p[i] = {x, y, ~i};
        // 取反，便于判断该点的类型。
    }

    vector<point> query = p;
    int q;
    cin >> q;
    rep(i, 0, q) {
        ll x, y;
        cin >> x >> y;
        query.push_back({x, y, i});
    }
    // 我们需要将所有点进行排序，如果检查的点和多边形的点是同一个点，由于负数，多边形的点优先排在前面
    sort(query.begin(), query.end());

    vector<int> ans(q);

    int u = -1, d = -1;
    for (auto pp : query) {
        int i = pp[2];
        if (i < 0) {  // 多边形的点
            i = ~i;
            if (u == -1) {  // 从左至右第一个扫到的点
                u = i;
                d = i;
            } else {
                // 多边形的点编号为0到n-1，通过模运算可以形成循环
                // 在上凸包上扫到的下一个点应该是u-1，下凸包扫到的下一个点是u+1
                if ((u - 1 + n) % n == i)
                    u = i;
                if ((d + 1) % n == i)
                    d = i;
            }
        } else {            // 需检查的点
            if (u == -1) {  // 在没有扫到多边形的点，所以在该点外面
                ans[i] = 0;
            } else {
                // 我们需要让pp点在多边形内部时，相对的向量都是在左侧。所以注意向量的两个点的顺序。
                int r1 = check(p[(u - 1 + n) % n], p[u], pp);
                int r2 = check(p[d], p[(d + 1) % n], pp);
                if (r1 == 1 || r2 == 1) {
                    ans[i] = 1;
                } else if (r1 == 2 && r2 == 2) {
                    ans[i] = 2;
                } else {
                    ans[i] = 0;
                }
            }
        }
    }

    vector<string> S({"OUT", "ON", "IN"});
    for (auto x : ans)
        cout << S[x] << endl;
}
