#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define MOD 998244353
using namespace std;

template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
    return os << '[' << p.first << ", " << p.second << ']';
}
template <class t>
ostream& operator<<(ostream& os, const vector<t>& v) {
    os << '[';
    int s = 1;
    for (auto e : v) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << e;
    }
    return os << ']';
}
template <class t, class u>
ostream& operator<<(ostream& os, const map<t, u>& mp) {
    os << '{';
    int s = 1;
    for (auto [x, y] : mp) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << x << ": " << y;
    }
    return os << '}';
}

template <typename T>
struct Heap {
    std::priority_queue<T> p, q;
    int size() { return p.size() - q.size(); }
    void push(T x) { p.push(x); }
    int top() {
        while (q.size() && p.top() == q.top())
            p.pop(), q.pop();
        return p.top();
    }
    void pop() {
        while (q.size() && p.top() == q.top())
            p.pop(), q.pop();
        p.pop();
    }
    void erase(T x) { q.push(x); }
};

#define N 200005

#define LS (id << 1)
#define RS (id << 1 | 1)

Heap<int> st[4 * N];
int idx[N];

void build(int id, int l, int r, vector<int>& a) {
    if (l == r) {
        idx[l] = id;
        st[id].push(a[l]);
        return;
    }
    int m = l + r >> 1;
    build(LS, l, m, a);
    build(RS, m + 1, r, a);
}

void add(int id, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
        st[id].push(v);
        return;
    }
    int m = l + r >> 1;
    if (ql <= m)
        add(LS, l, m, ql, qr, v);
    if (m < qr)
        add(RS, m + 1, r, ql, qr, v);
}

void del(int id, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
        st[id].erase(v);
        return;
    }
    int m = l + r >> 1;
    if (ql <= m)
        del(LS, l, m, ql, qr, v);
    if (m < qr)
        del(RS, m + 1, r, ql, qr, v);
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n, a);
    int q;
    cin >> q;
    vector<vector<int>> p(q + 1);
    for (int i = 1; i <= q; i++) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            p[i] = vector<int>{l, r, x};
            add(1, 1, n, l, r, x);
        } else if (opt == 2) {
            int x;
            cin >> x;
            del(1, 1, n, p[x][0], p[x][1], p[x][2]);
        } else {
            int x;
            cin >> x;
            int u = idx[x];
            int ans = 0;
            while (u) {
                if (st[u].size())
                    ans = max(ans, st[u].top());
                u >>= 1;
            }
            cout << ans << "\n";
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