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
    if (a == b) {
        cout << "1 " << n << "\n";
        return;
    }
    int l = 0, r = n - 1;
    while (a[l] == b[l])
        l++;
    while (a[r] == b[r])
        r--;
    while (l > 0 && b[l - 1] <= b[l])
        l--;
    while (r < n - 1 && b[r] <= b[r + 1])
        r++;
    cout << l + 1 << " " << r + 1 << "\n";
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