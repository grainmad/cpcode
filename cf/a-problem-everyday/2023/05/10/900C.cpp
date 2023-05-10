
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 100005
#define MOD 998244353
using namespace std;

int A[N];

void add(int x) {
    for (int i = x; i < N; i += i & -i) {
        A[i]++;
    }
}

int ask(int x) {
    int rt = 0;
    for (int i = x; i > 0; i = i & (i - 1)) {
        rt += A[i];
    }
    return rt;
}

void sol() {
    int n;
    cin >> n;
    vector<int> st, c(n + 1, 0), rec(n + 1, 0);
    int sz = 0;
    // rec[i] i是否已经是 record
    // c[i] 删除i后能能产生的record数
    // 对于i，删掉它，record 将变为 record总数-rec[i]+c[i]
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x);
        while (st.size() && st.back() < x)
            st.pop_back();
        if (st.size() == 1 && ask(x) == i)
            c[st.back()]++;
        st.push_back(x);
        if (st.size() == 1) {
            sz++;
            rec[x]++;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     if (rec[i])
    //         cout << i << " ";
    // }
    // cout << "\n";
    int mx = 0, ans = 1;
    for (int i = n; i > 0; i--) {
        int e = sz - rec[i] + c[i];
        // cout << i << " " << e << "\n";
        if (e >= mx) {
            mx = e;
            ans = i;
        }
    }
    cout << ans << "\n";
}
int main() {
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
