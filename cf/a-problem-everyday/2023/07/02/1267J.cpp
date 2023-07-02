
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    set<int> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
        st.insert(x);
    }
    int ans = n;
    int mx = *max_element(a.begin(), a.end()) + 1;
    for (int i = 1; i <= mx; i++) {
        int t = 0;
        for (int j : st) {
            if (a[j] % i == 0)
                t += a[j] / i;
            else if (a[j] / i + a[j] % i >= i - 1)
                t += a[j] / i + 1;
            else {
                t = n;
                break;
            }
        }
        ans = min(ans, t);
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
