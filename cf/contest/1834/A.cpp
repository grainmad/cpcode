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
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;
    int sum = accumulate(a.begin(), a.end(), 0);
    int neg = count(a.begin(), a.end(), -1) % 2;
    int ans = 0;
    for (int i : a) {
        if (i == 1)
            continue;
        if (sum < 0 || neg == 1)
            sum += 2, ans++, neg = 1 - neg;
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