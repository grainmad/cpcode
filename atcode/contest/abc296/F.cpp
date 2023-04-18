#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

struct BIT {
    vector<int> a;
    BIT(int n) : a(n, 0) {}
    int ask(int x) {
        int rt = 0;
        while (x) {
            rt += a[x];
            x = x & (x - 1);
        }
        return rt;
    }
    void add(int x) {
        while (x < a.size()) {
            a[x]++;
            x += x & -x;
        }
    }
};

int check(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a != b)
        return -1;
    for (int i = 1; i < a.size(); i++) {
        if (a[i - 1] == a[i])
            return 1;
    }
    return 0;
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& i : a)
        cin >> i;
    for (int& i : b)
        cin >> i;
    int res = check(a, b);
    if (res == 1) {
        cout << "Yes\n";
    } else if (res == -1) {
        cout << "No\n";
    } else {
        BIT fw1(n + 1), fw2(n + 1);
        int c1 = 0, c2 = 0;
        for (int i : a) {
            c1 += fw1.ask(i);
            fw1.add(i);
        }
        for (int i : b) {
            c2 += fw2.ask(i);
            fw2.add(i);
        }
        if ((c1 - c2) % 2 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
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