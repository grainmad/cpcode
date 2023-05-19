
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 1000005
#define MOD 998244353
using namespace std;

int cur = 0;
int ti[N], cnt[N];

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a)
        cin >> i;
    int mx = 0;
    for (int i : a) {
        mx = max(mx, (int)count(a.begin(), a.end(), i));
    }
    if (mx >= n / 2) {
        cout << "-1\n";
        return;
    }
    int sz = max(*max_element(a.begin(), a.end()),
                 abs(*min_element(a.begin(), a.end())));
    set<int, greater<int>> st;
    for (int x : a) {
        for (int y : a) {
            int dif = abs(y - x);
            for (int i = 1; i * i <= dif; i++) {
                if (dif % i == 0)
                    st.insert(i), st.insert(dif / i);
            }
        }
    }
    for (int i : st) {
        for (int x : a) {
            int cnt = 0;
            for (int y : a) {
                if (abs(y - x) % i == 0)
                    cnt++;
            }
            if (cnt >= n / 2) {
                cout << i << "\n";
                return;
            }
        }
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
