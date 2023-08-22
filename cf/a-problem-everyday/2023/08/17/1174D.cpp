
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    vector<int> v(1 << 18);
    v[0] = 1;
    int n, x;
    cin >> n >> x;
    vector<int> a = {0};
    for (int i = 1; i < 1 << n; i++) {
        if (v[x ^ i])
            continue;
        v[i] = 1;
        a.push_back(i);
    }
    cout << a.size() - 1 << endl;
    for (int i = 1; i < a.size(); i++) {
        cout << (a[i - 1] ^ a[i]) << " ";
    }
    cout << '\n';
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
