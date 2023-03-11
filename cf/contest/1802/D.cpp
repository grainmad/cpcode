#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    map<int, vector<int>, greater<int>> mp;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        st.insert(y);
    }
    int ans = 1e9 + 8, mx = -1e9 - 8;
    for (auto& [i, j] : mp) {
        // cout << i << ": ";
        // for (int k : j) {
        //     cout << k << " ";
        // }
        // cout << endl;
        ans = min(ans, abs(mx - i));
        if (mx < i) {
            if (j.size() == 1) {
                st.erase(st.find(j[0]));
            }
            auto it = st.upper_bound(i);
            if (it != st.end())
                ans = min(ans, abs(*it - i));
            if (it != st.begin())
                ans = min(ans, abs(*--it - i));
            for (int k : j) {
                if (j.size() > 1)
                    st.erase(st.find(k));
                mx = max(mx, k);
            }
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