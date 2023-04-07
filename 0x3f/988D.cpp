#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    set<int> st;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        st.insert(x);
    }
    for (int i : st) {
        for (int j = 0; j < 32; j++) {
            vector<int> t(1, i);
            if (st.count(i - (1LL << j)))
                t.push_back(i - (1LL << j));
            if (st.count(i + (1LL << j)))
                t.push_back(i + (1LL << j));
            if (ans.size() < t.size())
                ans = t;
        }
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << " ";
    }
    cout << "\n";
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