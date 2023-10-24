// #include <bits/stdc++.h>
// // #define SINGLE_INPUT
// #define ull unsigned long long
// #define ll long long
// #define N 600005
// #define MOD 998244353
// using namespace std;

// ll a[N];

// struct Seg {
//     int l, r;
//     ll mxval, mnval, tag;
// } seg[N << 2];

// void push_up(Seg& u, const Seg& l, const Seg& r) {
//     u.mxval = max(l.mxval, r.mxval);
//     u.mnval = min(l.mnval, r.mnval);
// }

// void push_down(Seg& u, Seg& l, Seg& r) {
//     l.mxval += u.tag;
//     l.mnval += u.tag;
//     l.tag += u.tag;
//     r.mxval += u.tag;
//     r.mnval += u.tag;
//     r.tag += u.tag;

//     u.tag = 0;
// }

// void seg_build(int id, int l, int r) {
//     seg[id].l = l;
//     seg[id].r = r;
//     seg[id].mxval = seg[id].mnval = seg[id].tag = 0;
//     if (l == r) {
//         // cin >> seg[id].val;
//         return;
//     }
//     int m = l + r >> 1;
//     seg_build(id << 1, l, m);
//     seg_build(id << 1 | 1, m + 1, r);
//     push_up(seg[id], seg[id << 1], seg[id << 1 | 1]);
// }

// void seg_update(int id, int l, int r, ll val) {
//     if (l <= seg[id].l && seg[id].r <= r) {
//         seg[id].mxval += val;
//         seg[id].mnval += val;
//         seg[id].tag += val;
//         return;
//     }
//     push_down(seg[id], seg[id << 1], seg[id << 1 | 1]);
//     int m = seg[id].l + seg[id].r >> 1;
//     if (l <= m)
//         seg_update(id << 1, l, r, val);
//     if (m < r)
//         seg_update(id << 1 | 1, l, r, val);
//     push_up(seg[id], seg[id << 1], seg[id << 1 | 1]);
// }

// void sol() {
//     int n, m;
//     cin >> n >> m;
//     map<int, int> mp;
//     mp[1];
//     mp[m];
//     vector<pair<int, int>> sg(n);
//     for (auto& [i, j] : sg) {
//         cin >> i >> j;
//         mp[i];
//         if (i - 1 >= 1)
//             mp[i - 1];
//         if (i + 1 <= m)
//             mp[i + 1];
//         mp[j];
//         if (j - 1 >= 1)
//             mp[j - 1];
//         if (j + 1 <= m)
//             mp[j + 1];
//     }
//     int sz = 0;
//     for (auto& [i, j] : mp)
//         j = ++sz;
//     seg_build(1, 1, sz);
//     sort(sg.begin(), sg.end());
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
//     ll ans = 0;
//     int p = 0;
//     for (int i = 1; i <= sz; i++) {
//         while (q.size() && mp[q.top().first] < i) {
//             auto [y, x] = q.top();
//             q.pop();
//             seg_update(1, mp[x], mp[y], -1);
//         }

//         while (p < n && mp[sg[p].first] == i) {
//             q.emplace(sg[p].second, sg[p].first);
//             seg_update(1, mp[sg[p].first], mp[sg[p].second], 1);
//             p++;
//         }
//         // cout << i << ",  " << seg[1].mxval << " " << seg[1].mnval << endl;
//         ans = max(ans, seg[1].mxval - seg[1].mnval);
//     }
//     cout << ans << "\n";
// }

// int main() {
//     cout << setprecision(15) << fixed;
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
// #ifndef SINGLE_INPUT
//     int t;
//     cin >> t;
//     while (t--) {
//         sol();
//     }
// #else
//     sol();
// #endif
//     return 0;
// }
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> sg(n);
    for (auto& [i, j] : sg)
        cin >> i >> j;
    int ans = 0;
    vector<pair<int, int>> a;
    int c = 0;
    for (auto [i, j] : sg) {
        if (i != 1)
            a.emplace_back(i, -1), a.emplace_back(j, 1);
    }
    sort(a.begin(), a.end());
    for (auto [i, j] : a) {
        c -= j;
        ans = max(ans, c);
    }
    a.clear();
    c = 0;
    for (auto [i, j] : sg) {
        if (j != m)
            a.emplace_back(i, -1), a.emplace_back(j, 1);
    }
    sort(a.begin(), a.end());
    for (auto [i, j] : a) {
        c -= j;
        ans = max(ans, c);
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