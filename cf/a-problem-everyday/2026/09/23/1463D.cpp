
#include <bits/stdc++.h>
// #define SINGLE_INPUT     // 多测时注释掉这行；单测时取消注释
#define ll long long
#define ull unsigned long long
#define N 500005
#define MOD 998244353
using namespace std;

random_device seed;
ranlux48 engine(seed());
int random(int l, int r) {
    uniform_int_distribution<> distrib(l, r);
    return distrib(engine);
}
template<class t,class u> ostream& operator<<(ostream& os,const pair<t,u>& p) {
    return os<<'['<<p.first<<", "<<p.second<<']';
}
template<class t> ostream& operator<<(ostream& os,const vector<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
}
template<class t> ostream& operator<<(ostream& os,const set<t>& v) {
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
    // 读入 -> 求解 -> 输出（cout << ... << "\n"）
    int n;
    cin >> n;
    vector<int> b(n);
    for (auto &x : b) cin >> x;
    sort(b.begin(), b.end());
    vector<char> inB(2 * n + 2, 0);
    for (int x : b) inB[x] = 1;
    vector<int> a;
    a.reserve(n);
    for (int v = 1; v <= 2 * n; v++)
        if (!inB[v]) a.push_back(v);

    auto func = [&](vector<int>& a, vector<int>& b) {
        int x = n;
        int l=n-1, r=n-1;
        while (l>=0 && b[l] > a[r]) l--, x--;
        while (l>=0 && r>=0) {
            if (b[l] < a[r]) l--, r--;
            else l--, x--;
        }
        return x;
    };

    cout << func(a, b)+func(b, a)-n+1 << "\n";
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
