#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

template <class t, class u>
ostream& operator<<(ostream& os, const pair<t, u>& p) {
    return os << '[' << p.first << ", " << p.second << ']';
}
template <class t>
ostream& operator<<(ostream& os, const vector<t>& v) {
    os << '[';
    int s = 1;
    for (auto e : v) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << e;
    }
    return os << ']';
}
template <class t, class u>
ostream& operator<<(ostream& os, const map<t, u>& mp) {
    os << '{';
    int s = 1;
    for (auto [x, y] : mp) {
        if (s)
            s = 0;
        else
            os << ", ";
        os << x << ": " << y;
    }
    return os << '}';
}

void sol() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> x(256);
    for (char i = 'a'; i <= 'z'; i++) {
        x[i] = i;
    }
    int q;
    cin >> q;
    while (q--) {
        string a, b;
        cin >> a >> b;
        for (char i = 'a'; i <= 'z'; i++) {
            if (x[i] == a[0])
                x[i] = b[0];
        }
    }
    for (auto i : s) {
        cout << char(x[i]);
    }
    cout << '\n';
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