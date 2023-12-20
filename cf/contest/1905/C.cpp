#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> st;
    for (int i = 0; i < n; i++) {
        while (st.size() && s[st.back()] < s[i]) {
            st.pop_back();
        }
        st.push_back(i);
    }
    // for (int i : st) {
    //     cout << i << " ";
    // }
    // cout << "st \n";
    int sz = st.size();
    for (int i = 0; i < sz / 2; i++) {
        swap(s[st[i]], s[st[sz - 1 - i]]);
    }
    // cout << s << endl;
    if (is_sorted(s.begin(), s.end())) {
        int ans = sz;
        for (int i : st)
            if (s[i] == s[st.back()])
                ans--;
        cout << ans << "\n";
    } else {
        cout << "-1\n";
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