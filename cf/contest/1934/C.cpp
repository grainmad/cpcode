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

int X1 = 1, Y1 = 1;
int X2 = 5, Y2 = 4;

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    // return min(abs(x - X1) + abs(y - Y1), abs(x - X2) + abs(y - Y2));
    int rt;
    cin >> rt;
    return rt;
}

void sol() {
    int n, m;
    cin >> n >> m;
    int a = ask(1, 1);
    int b = ask(1, m);
    int c = ask(n, 1);
    int x1 = (a + n + 1 - c) / 2, y1 = (a + c - n + 3) / 2;
    int x2 = (3 + a + b - m) / 2, y2 = (m - b + a + 1) / 2;
    if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && ask(x1, y1) == 0) {
        cout << "! " << x1 << " " << y1 << endl;
    } else {
        cout << "! " << x2 << " " << y2 << endl;
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