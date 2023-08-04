
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

vector<int> ans;
int a[4];
int sum = 0;

bool dfs(int p) {
    return ans.size() == sum;
}

void sol() {
    for (int i = 0; i < 4; i++)
        cin >> a[i], sum += a[i];
    for (int i = 0; i < 4; i++) {
        if (dfs(i)) {
            cout << "YES\n";
            for (int i : ans) {
                cout << i << " ";
            }
            cout << "\n";
            return;
        } else {
            while (ans.size()) {
                a[ans.back()]++;
                ans.pop_back();
            }
        }
    }
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
