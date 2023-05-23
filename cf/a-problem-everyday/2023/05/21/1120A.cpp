
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

int a[N], mx[N], mp[N];

void sol() {
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    set<int> st;
    for (int i = 1; i <= s; i++) {
        int b;
        cin >> b;
        mx[b]++;
        st.insert(b);
    }
    int d = st.size();
    int cur = 0;
    for (int r = 1, l = 0; r <= m; r++) {
        // cout << l << " " << r << "\n";
        if (++mp[a[r]] == mx[a[r]])
            cur++;

        if (cur < d)
            continue;
        while (cur == d) {
            if (mp[a[l + 1]]-- == mx[a[l + 1]])
                cur--;
            l++;
        }
        // cout << l << " " << r << "\n";
        // 包含了模板的区间为[l,r]。
        // r-l+1 如果不足k个，r<=k不用删，否则删除r%k个
        // r-l+1
        // 如果大于k个，需要删除r-l+1-k个以达到当前区间为k个，前方需要删除(l-1)%k个
        if (r - l + 1 < k) {
            if (r <= k) {
                cout << "0\n";
                return;
            }
            if (r % k <= m - k * n) {
                cout << r % k << "\n";
                for (int i = 1; i <= r % k; i++) {
                    cout << i << " ";
                }
                return;
            }
        } else {
            int c = r - l - k + 1 + (l - 1) % k;
            if (c <= m - k * n) {
                cout << c << "\n";
                for (int i = 1; i <= (l - 1) % k; i++) {
                    cout << i << " ";
                }
                for (int i = l, cnt = 0; cnt < r - l - k + 1 && i <= r; i++) {
                    if (--mx[a[i]] < 0) {
                        cout << i << " ";
                        cnt++;
                    }
                }
                return;
            }
        }
    }
    cout << "-1\n";
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
