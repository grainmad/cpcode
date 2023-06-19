
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

// vector<int> a = {1, 2, 0, 3};
vector<int> a = {1, 2, 0, 1};
// vector<int> a = {1, 2, 3, 3};

int getxor(int x, int y) {
    cout << "XOR " << x << " " << y << endl;
    // return a[x - 1] ^ a[y - 1];
    int rt;
    cin >> rt;
    return rt;
}
int getand(int x, int y) {
    cout << "AND " << x << " " << y << endl;
    // return a[x - 1] & a[y - 1];
    int rt;
    cin >> rt;
    return rt;
}

int xora1[(1 << 16) + 5];
int cnt[(1 << 16) + 5];

void sol() {
    int n;
    cin >> n;
    int z = -1;
    for (int i = 2; i <= n; i++) {
        xora1[i] = getxor(1, i);
        if (xora1[i] == 0)
            z = i;
        cnt[xora1[i]]++;
    }
    int p = -1;
    for (int i = 1; i < n; i++) {
        if (cnt[i] > 1) {
            p = i;
            break;
        }
    }
    vector<int> ans(n + 1);
    if (z != -1) {  // 存在0，a1 与 az 相等
        ans[1] = getand(1, z);
    } else if (p != -1) {  // a2...an中有相等
        vector<int> x;
        for (int i = 2; i <= n; i++) {
            if (xora1[i] == p)
                x.push_back(i);
        }
        int r = getand(x[0], x[1]);
        ans[1] = r ^ xora1[x[0]];
    } else {  // 不存在重复的数
        int x = 0;
        for (int i = 2; i <= n; i++) {
            if (xora1[i] == n - 1)
                x = i;
        }
        int y = (x == 2 ? 3 : 2);
        int a1x = xora1[x];
        int a1y = xora1[y] + 2 * getand(1, y);
        int ayx = (xora1[y] ^ xora1[x]) + 2 * getand(y, x);
        ans[1] = (a1x - ayx + a1y) / 2;
    }
    for (int i = 2; i <= n; i++) {
        ans[i] = ans[1] ^ xora1[i];
    }
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
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
