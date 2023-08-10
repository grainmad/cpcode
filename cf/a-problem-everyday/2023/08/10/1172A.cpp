
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;
    auto check = [&]() {
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 1)
                p = i;
        }
        int ok = 1;
        for (int i = p; i < n; i++) {
            if (b[i] != i - p + 1)
                ok = 0;
        }
        if (ok) {
            set<int> st(a.begin(), a.end());
            int cur = n - p + 1;
            for (int i = 0; i < p; i++) {
                if (st.count(cur))
                    cur++;
                else
                    return false;
                st.insert(b[i]);
            }
            cout << p << "\n";
            return true;
        }
        return false;
    };
    if (check())
        return;
    set<int> st(a.begin(), a.end());
    int add = 0, cur = 1;
    for (int i : b) {
        // cout << i << " ";
        if (st.count(cur))
            cur++;
        else
            add++;
        st.insert(i);
    }
    // cout << "\n";
    cout << n + add << "\n";
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
