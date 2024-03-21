#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
#define N 500005
#define MOD 998244353
using namespace std;

template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n), b;
    for (auto& i : a)
        cin >> i;
    b.push_back(a[n - 1]);
    int ok = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] <= b.back()) {
            b.push_back(a[i]);
            continue;
        }
        if (a[i] < 10) {
            if (a[i] > b.back()) {
                ok = 0;
            } else {
                b.push_back(a[i]);
            }
        } else {
            if (a[i] / 10 > a[i] % 10 || a[i] % 10 > b.back()) {
                ok = 0;
            } else {
                b.push_back(a[i] % 10);
                b.push_back(a[i] / 10);
            }
        }
    }
    if (ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
