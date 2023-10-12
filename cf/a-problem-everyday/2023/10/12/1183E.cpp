
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k == 1) {
        cout << "0\n";
        return;
    }
    set<string> st;
    queue<string> q;
    q.push(s);
    st.insert(s);
    int stp = 1;
    int ans = 0;
    while (q.size()) {
        int sz = q.size();
        for (int i=0; i<sz; i++) {
            string u = q.front();
            q.pop();
            int usz = u.size();
            for (int j=0; j<usz; j++) {
                string t = u.substr(0, j) + u.substr(j+1, usz-j-1);
                if (st.count(t)) continue; 
                st.insert(t);
                q.push(t);
                ans += stp;
                if (st.size() == k) {
                    cout << ans << "\n";
                    return ;
                }
            }
        }
        stp++;
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
