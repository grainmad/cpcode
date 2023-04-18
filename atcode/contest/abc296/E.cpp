#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 200005
#define MOD 998244353
using namespace std;

int a[N], in[N];

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        in[a[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (--in[a[u]] == 0)
            q.push(a[u]);
    }
    cout << count(in + 1, in + n + 1, 1) << "\n";
}
int main() {
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