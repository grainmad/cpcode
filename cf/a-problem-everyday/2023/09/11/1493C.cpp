
#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

void sol() {
    int k, n;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> c(26);
    for (char i : s)
        c[i - 'a']++;
    int cnt = 0;
    for (int t : c)
        cnt += t % k;
    if (cnt == 0) {
        cout << s << "\n";
        return;
    }
    for (int i = n - 1; i >= 0; i--) {
        c[s[i] - 'a']--;
        for (int j = s[i] - 'a' + 1; j < 26; j++) {
            c[j]++;
            int sum = 0;
            for (int t : c)
                sum += (k - t % k) % k;
            if (n - 1 - i >= sum && (n - 1 - i - sum) % k == 0) {
                cout << s.substr(0, i);
                cout << char(j + 'a');
                cout << string(n - 1 - i - sum, 'a');
                for (int x = 0; x < 26; x++) {
                    // cout << x << " " << (k - c[x] % k) % k << endl;
                    for (int y = 0; y < (k - c[x] % k) % k; y++) {
                        cout << char(x + 'a');
                    }
                }
                cout << "\n";
                return;
            }
            c[j]--;
        }
    }
    cout << "-1\n";
}

int main() {
    cout << setprecision(15) << fixed;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef SINGLE_INPUT
    int t;
    cin >> t;
    // if (t == 7081) {
    //     for (int i = 0; i < 7081; i++) {
    //         int k, n;
    //         cin >> n >> k;
    //         string s;
    //         cin >> s;
    //         if (271 == i) {
    //             cout << n << " " << k << endl;
    //             cout << s << endl;
    //         }
    //     }
    // } else
    while (t--) {
        sol();
    }
#else
    sol();
#endif
    return 0;
}
