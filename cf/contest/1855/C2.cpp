#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int n, nc = 0, pc = 0;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
        if (i < 0)
            nc++;
        if (i > 0)
            pc++;
    }

    int mx = *max_element(a.begin(), a.end());
    int pmx = find(a.begin(), a.end(), mx) - a.begin();
    int mn = *min_element(a.begin(), a.end());
    int pmn = find(a.begin(), a.end(), mn) - a.begin();
    vector<pair<int, int>> ans;
    if (mx >= -mn) {
        if (nc <= 12) {
            for (int i = 0; i < n; i++) {
                if (a[i] < 0)
                    ans.emplace_back(i, pmx);
            }
            for (int i = 1; i < n; i++) {
                ans.emplace_back(i, i - 1);
            }
        } else {  // negtive > 12 , postive <= 7, 31-19-7=5, -2^5<-20
            for (int i = 0; i < 5; i++) {
                ans.emplace_back(pmn, pmn);
            }
            for (int i = 0; i < n; i++) {
                if (a[i] > 0)
                    ans.emplace_back(i, pmn);
            }
            for (int i = n - 1; i > 0; i--) {
                ans.emplace_back(i - 1, i);
            }
        }
    } else {
        if (pc <= 12) {
            for (int i = 0; i < n; i++) {
                if (a[i] > 0)
                    ans.emplace_back(i, pmn);
            }
            for (int i = n - 1; i > 0; i--) {
                ans.emplace_back(i - 1, i);
            }
        } else {  // postive > 12 , negtive <= 7, 31-19-7=5, 2^5>20
            for (int i = 0; i < 5; i++) {
                ans.emplace_back(pmx, pmx);
            }
            for (int i = 0; i < n; i++) {
                if (a[i] < 0)
                    ans.emplace_back(i, pmx);
            }
            for (int i = 1; i < n; i++) {
                ans.emplace_back(i, i - 1);
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto [i, j] : ans) {
        cout << i + 1 << " " << j + 1 << "\n";
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