#include <bits/stdc++.h>
// #define LOCAL
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll& i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());

    ll sum_b = 0;
    vector<ll> pre_min_b(n);  // b[i] = a[i]-i, pre_min_b[i] = min(b[0...i])
    for (int i = 0; i < n; i++) {
        if (i == 0)
            pre_min_b[i] = a[i];
        else
            pre_min_b[i] = min(a[i] - i, pre_min_b[i - 1]);
        sum_b += a[i] - i;
    }
    while (q--) {
        ll k, mn;
        cin >> k;
        if (n == 1) {
            mn = a[0] - k / 2 + (k % 2 ? k : 0);
        } else if (k < n) {
            mn = min(pre_min_b[k - 1] + k, a[k]);
        } else {
            if ((k - n + 1) % 2) {
                mn = pre_min_b[n - 1] + k;
                // 分配 (k-n)/2个-1 到 b[0]+k, b[1]+k, ..., b[n-2]+k, b[n-1]+k
                if (sum_b + n * (k - mn) <
                    (k - n) / 2) {  // -1多了，最小值不是mn了
                    ll d = (k - n) / 2 - sum_b - n * (k - mn);
                    mn -= (d + n - 1) / n;
                }
            } else {
                mn = min(pre_min_b[n - 2] + k, a[n - 1]);
                // 分配 (k-n+1)/2个-1 到 b[0]+k, b[1]+k, ..., b[n-2]+k, a[n-1]
                //  sum_b-(a[n-1]-(n-1))+a[n-1] + k*(n-1)= 序列总和
                //  考虑序列每个值都变为mn，序列总和-mn*n < (k-n+1)/2
                //  则最小值将比mn小
                if (sum_b + (k + 1) * (n - 1) - mn * n < (k - n + 1) / 2) {
                    ll d = (k - n + 1) / 2 - sum_b - (k + 1) * (n - 1) + mn * n;
                    mn -= (d + n - 1) / n;
                }
            }
        }
        cout << mn << " ";
    }
    cout << "\n";
}
int main() {
#ifdef LOCAL
    auto start_time = clock();
    cerr << setprecision(3) << fixed;
#endif
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
#ifdef LOCAL
    auto end_time = clock();
    cerr << "Execution time: "
         << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
    return 0;
}