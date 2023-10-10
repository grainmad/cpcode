#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1), in(n + 1), c(n + 1, -1);
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        in[a[i]]++;
        st.insert(i);
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            c[i] = 0;
        }
        // cout << in[i] << " ";
    }
    // cout << endl;
    for (int _ = 0; _ < n; _++) {
        if (q.empty()) {
            q.push(*st.begin());
            c[*st.begin()] = 1;
            st.erase(st.begin());
        }
        int u = q.front();
        q.pop();
        st.erase(u);
        if (c[u] == 0) {
            if (c[a[u]] == 0) {
                cout << "-1\n";
                return;
            }
            if (c[a[u]] == -1) {
                c[a[u]] = 1;
                q.push(a[u]);
            }
        }
        if (c[u] == 1) {
            in[a[u]]--;
            if (in[a[u]] == 0) {
                if (c[a[u]] == 1) {
                    cout << "-1\n";
                    return;
                }
                if (c[a[u]] == -1) {
                    c[a[u]] = 0;
                    q.push(a[u]);
                }
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            ans.push_back(a[i]);
        }
        if (c[i] == -1) {
            cout << "-1\n";
            return;
        }
        // cout << in[i] << " ";
    }
    // cout << endl;
    if (ans.size() == 0) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << "\n";
    for (auto i : ans)
        cout << i << " ";
    cout << "\n";
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