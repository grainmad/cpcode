
#include <bits/stdc++.h>
#define SINGLE_INPUT
#define ll long long
#define ull unsigned long long
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

// ax + by + c = 0
ll a, b, c;
ll X1, Y1, X2, Y2;

// (x, y')  y' = (-c-ax)/b
pair<double, double> getp1(double x, double y) {
    return {x, (-c-a*x)/b};    
}

// (x', y)  x' = (-c-by)/a
pair<double, double> getp2(double x, double y) {
    return {(-c-b*y)/a, y};    
}

double dis(double a1, double b1, double a2, double b2) {
    return sqrt((a1-a2)*(a1-a2)+(b1-b2)*(b1-b2));
}

void sol() {
    cin >> a >> b >> c;
    cin >> X1 >> Y1 >> X2 >> Y2;
    vector<pair<double, double>> v1;
    v1.push_back(getp1(X1, Y1));
    v1.push_back(getp2(X1, Y1));
    vector<pair<double, double>> v2;
    v2.push_back(getp1(X2, Y2));
    v2.push_back(getp2(X2, Y2));
    // cout << v1 << " " << v2 << endl;
    double ans = abs(X1-X2)+abs(Y1-Y2);
    for (auto [a1, b1]:v1) {
        for (auto [a2, b2]:v2) {
            ans = min(ans, dis(X1, Y1, a1, b1)+dis(a1, b1, a2, b2)+dis(a2, b2, X2, Y2));
        }
    }
    cout << ans << "\n";
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
