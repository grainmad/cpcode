
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;


void sol() {
    ll n, p;
    cin >> n >> p;
    set<ll> st;
    vector<ll> a(n+1);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    // 0 到 a[n-1] 都存在
    int ok = 1;
    for (int i=a[n]; i>=0; i--) {
        if (st.count(i) == 0) {
            ok = 0;
            break;
        }
    }
    if (ok) {
        int i;
        for (i=p-1; i>a[n]; i--) {
            if (st.count(i) == 0) {
                break;
            }
        }
        cout << (i-a[n]) << "\n";
    } else {
        st.insert(0);
        for (int i=n-1; i>=0; i--) {
            if (a[i] != p-1) {
                st.insert(a[i]+1);
                break;
            }
        }
        for (int i=a[n]-1; i>=0; i--) {
            if (st.count(i) == 0) {
                cout << i+p-a[n] << "\n";
                return ;
            }
        }
        cout << p-a[n] << "\n";
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