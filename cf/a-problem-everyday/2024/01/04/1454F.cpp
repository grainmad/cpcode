
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
#define INF 0x3f3f3f3f
#define ls (id << 1)
#define rs (id << 1 | 1)
using namespace std;

#define MAXN 200005
int st[MAXN][30];  // st[i][j] 代表区间[i, i+2^j)最小值

void ST(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {             // 区间大小
        for (int i = 0; i + (1 << j) - 1 < n; i++) {  // 区间下限
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int ask(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1)
        k++;
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    ST(a);
    // [0, p] 中找最小x使得 [x, p] 中最小值为val
    auto lb = [&](int p, int val) {
        int l = 0, r = p + 1;
        while (l < r) {
            int m = l + r >> 1;
            if (ask(m, p) < val)
                l = m + 1;
            else
                r = m;
        }
        return r;
    };
    // [0, p] 中找最大x使得 [x-1, p] 中最小值为val
    auto ub = [&](int p, int val) {
        int l = 0, r = p + 1;
        while (l < r) {
            int m = l + r >> 1;
            if (ask(m, p) <= val)
                l = m + 1;
            else
                r = m;
        }
        return r;
    };
    vector<int> pmx(n + 1);
    pmx[0] = a[0];
    for (int i = 1; i < n; i++) {
        pmx[i] = max(pmx[i - 1], a[i]);
    }
    int smx = 0;
    for (int i = n - 1; i >= 2; i--) {
        smx = max(smx, a[i]);
        int l1 = lower_bound(pmx.begin(), pmx.begin() + i, smx) - pmx.begin();
        int r1 = upper_bound(pmx.begin(), pmx.begin() + i, smx) - pmx.begin();
        // smx = [l1, r1)
        int l2 = lb(i - 1, smx);
        int r2 = ub(i - 1, smx);
        // cout << i << ": " << endl;
        // cout << l1 << " " << r1 << endl;
        // cout << l2 << " " << r2 << endl;
        // smx = [l2, r2)
        int sp = -1;
        if (l2 < r2 && l1 <= l2 - 1 && l2 - 1 < r1) {
            sp = l2;
        }
        if (l2 + 1 < r2 && l1 <= l2 && l2 < r1) {
            sp = l2 + 1;
        }
        if (sp != -1) {
            cout << "YES\n";
            cout << sp << " " << i - sp << " " << n - i << "\n";
            return;
        }
    }
    cout << "NO\n";
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
