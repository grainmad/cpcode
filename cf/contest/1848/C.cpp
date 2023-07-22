#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
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
    set<int> st;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && a[i] == 0)
            continue;
        int d = gcd(a[i], b[i]);
        a[i] /= d;
        b[i] /= d;
        st.insert(a[i] % 2 * 2 + b[i] % 2);
    }
    if (st.size() <= 1)
        cout << "YES\n";
    else
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
