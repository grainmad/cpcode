
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

void sol() {
    for (int i = 0; i < 4; i++)
        cin >> a[i], sum += a[i];
    for (int i = 0; i < 4; i++) {
        if (a[i] == 0)
            continue;
        ans.push_back(i);
        a[i]--;
        int c = i;
        for (int j = 1; j < sum; j++) {
            if (c - 1 >= 0 && a[c - 1]) {
                ans.push_back(--c);
                a[c]--;
            } else if (c + 1 < 4 && a[c + 1]) {
                ans.push_back(++c);
                a[c]--;
            } else
                break;
        }
        if (ans.size() == sum) {
            cout << "YES\n";
            for (int i : ans) {
                cout << i << " ";
            }
            cout << "\n";
            return;
        }
        while (ans.size())
            a[ans.back()]++, ans.pop_back();
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
