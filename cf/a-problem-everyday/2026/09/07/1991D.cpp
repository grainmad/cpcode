
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
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    // 读入 -> 求解 -> 输出（cout << ... << "\n"）
    int n;
    cin >> n;
    vector<int> c(n + 1);
    if (n == 1) {
        c[1] = 1;
    } else if (n <= 3) {          // 有边 1-2 (1^2=3)，2 色够
        c[1] = 1;
        for (int i = 2; i <= n; i++) c[i] = 2;
    } else if (n <= 5) {          // {1,3,4} 三角形 -> 3 色；5 只与 2 相邻
        int d[] = {0, 1, 2, 2, 3, 3};
        for (int i = 1; i <= n; i++) c[i] = d[i];
    } else {                      // {1,3,4,6} 是 K4 -> 4 色；u≡v (mod 4) ⟹ u^v 是 4 的倍数，非质数
        for (int i = 1; i <= n; i++) c[i] = i % 4 + 1;
    }
    cout << *max_element(c.begin() + 1, c.end()) << "\n";
    for (int i = 1; i <= n; i++) cout << c[i] << " \n"[i == n];
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
