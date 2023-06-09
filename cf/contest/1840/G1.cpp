#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 1000005
#define MOD 998244353
using namespace std;

vector<int> a = {3, 2, 1, 4, 5, 7, 6, 8, 9};

int cur = 0;
int getval(int k) {
    cur += k;
    cur %= a.size();
    cout << "cout " << k << " ";
    cout << "cin " << a[cur] << "\n";
    return a[cur];
}

int mp[N];

void sol() {
    int x;
    cin >> x;
    int stp = 1000;
    for (int i = 1; i <= stp; i++) {
        // int v = getval(1);
        cout << "+ 1" << endl;
        int v;
        cin >> v;
        if (mp[v] != 0) {
            cout << "! " << i - 1 << endl;
            return;
        }
        mp[v] = i;
    }
    for (int i = 2 * stp;; i += stp) {
        // int v = getval(stp);
        cout << "+ " << stp << endl;
        int v;
        cin >> v;
        if (mp[v] != 0) {
            cout << "! " << i - mp[v] << endl;
            return;
        }
        mp[v] = i;
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