#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

/*
13 = 1101
1 1 2 3 1
*/

void sol() {
    ll n;
    cin >> n;
    int b = 0;
    for (ll i=n; i>1; i>>=1) {
        b++;
    }
    vector<int> ans;
    ans.push_back(0);
    for (int i=b-1; i>=0; i--) {
        if (n>>i&1) ans.push_back(0);
        if (i!=0) ans.push_back(b-i);
    }
    cout << ans.size() << "\n";
    for (int i:ans) {
        cout << i << " ";
    }
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