#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define N 5000005
#define MOD 998244353
using namespace std;

int a[N], cnt[N];

void sol() {
    int a, b;
    cin >> a >> b;
    cout << cnt[a] - cnt[b] << "\n";
}
int main() {
    for (int i = 0; i < N; i++)
        a[i] = i;
    for (int i = 2; i < N; i++) {
        if (a[i] == 1)
            continue;
        int c = a[i];
        for (int j = i; j < N; j += i) {
            if (a[j] % c == 0) {
                a[j] /= c;
                cnt[j]++;
            }
        }
    }
    // for (int i = 0; i <= 16; i++) {
    //     cout << i << " " << cnt[i] << endl;
    // }
    for (int i = 1; i < N; i++) {
        cnt[i] += cnt[i - 1];
    }
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