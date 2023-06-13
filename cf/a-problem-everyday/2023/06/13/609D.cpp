
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

struct Node {
    int id, t, c;
    Node(int id, int t, int c) : id(id), t(t), c(c) {}
    bool operator<(const Node& o) const {
        if (t != o.t) {
            return t < o.t;
        } else if (t == 1) {
            return c > o.c;
        } else {
            return c < o.c;
        }
    }
};

void sol() {
    ll n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<ll> a(n), b(n);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;
    vector<Node> g;
    for (int i = 0; i < m; i++) {
        int t, c;
        cin >> t >> c;
        g.emplace_back(i + 1, t, c);
    }
    sort(g.begin(), g.end());
    // for (int i = 0; i < m; i++) {
    //     cout << g[i].id << " " << g[i].c << " " << g[i].t << "\n";
    // }
    ll l = 1, r = n + 1;
    while (l < r) {
        ll mid = l + r >> 1;
        int ok = 0;
        ll ma = *min_element(a.begin(), a.begin() + mid);
        ll mb = *min_element(b.begin(), b.begin() + mid);
        ll cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += (g[i].t == 1 ? ma : mb) * g[i].c;
            if (i >= k) {
                cnt -= (g[i - k].t == 1 ? ma : mb) * g[i - k].c;
            }
            if (i >= k - 1 && cnt <= s) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    if (r == n + 1) {
        cout << "-1\n";
    } else {
        cout << r << "\n";
        ll ma = *min_element(a.begin(), a.begin() + r);
        ll mb = *min_element(b.begin(), b.begin() + r);
        ll da, db;
        for (int i = 0; i < r; i++) {
            if (a[i] == ma)
                da = i + 1;
            if (b[i] == mb)
                db = i + 1;
        }
        ll cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += (g[i].t == 1 ? ma : mb) * g[i].c;
            if (i >= k) {
                cnt -= (g[i - k].t == 1 ? ma : mb) * g[i - k].c;
            }
            if (i >= k - 1 && cnt <= s) {
                for (int j = i - k + 1; j <= i; j++) {
                    cout << g[j].id << " " << (g[j].t == 1 ? da : db) << "\n";
                }
                break;
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
