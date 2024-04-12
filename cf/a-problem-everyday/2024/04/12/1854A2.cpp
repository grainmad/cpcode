
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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
template<class t,class u> ostream& operator<<(ostream& os,const map<t,u>& mp){
    os<<'{'; int s = 1;
    for(auto [x,y]:mp) { if (s) s = 0; else os << ", "; os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    int neg = 0, pos = 0, mx = 0, mn = 0;
    for (auto& i:a) {
        cin >> i;
        if (i<0) neg++;
        if (i>0) pos++;
    }
    for (int i=0; i<n; i++) {
        if (a[mx] < a[i]) mx = i;
        if (a[mn] > a[i]) mn = i;
    }
    // cout << a << endl;
    // cout << a[mx] << " " << a[mn] << endl;
    vector<pair<int,int>> ans;
    if (pos == 0) {
        for (int i=n-2; i>=0; i--) {
            ans.emplace_back(i, i+1);
        }
    } else if (neg == 0) {
        for (int i=1; i<n; i++) {
            ans.emplace_back(i, i-1);
        }
    } else if (a[mx] + a[mn] < 0) { // a[mx] < |a[mn]|
        if (pos <= 12) { // opt: 12+19 = 31 
            for (int i=0; i<n; i++) {
                if (a[i] > 0) {
                    ans.emplace_back(i, mn);
                }
            }
            for (int i=n-2; i>=0; i--) {
                ans.emplace_back(i, i+1);
            }
        } else { // a[mx] = 1, 2, 4, 8, 16, 32. opt: 5 + 7 + 19 = 31
            for (int i=0; i<5; i++) {
                ans.emplace_back(mx, mx);
            }
            for (int i=0; i<n; i++) { // most opt 7
                if (a[i] < 0) { 
                    ans.emplace_back(i, mx);
                }
            }
            for (int i=1; i<n; i++) {
                ans.emplace_back(i, i-1);
            }      
        }
    } else { // a[mx] > |a[mn]|
        if (neg <= 12) { // opt: 12+19 = 31 
            for (int i=0; i<n; i++) {
                if (a[i] < 0) {
                    ans.emplace_back(i, mx);
                }
            }
            for (int i=1; i<n; i++) {
                ans.emplace_back(i, i-1);
            }   
        } else { // a[mn] = -1, -2, -4, -8, -16, -32. opt: 5 + 7 + 19 = 31
            for (int i=0; i<5; i++) {
                ans.emplace_back(mn, mn);
            }
            for (int i=0; i<n; i++) {
                if (a[i] > 0) {
                    ans.emplace_back(i, mn);
                }
            }
            for (int i=n-2; i>=0; i--) {
                ans.emplace_back(i, i+1);
            }   
        }
    }
    cout << ans.size() << "\n";
    for (auto [x,y]:ans) {
        cout << x+1 << " " << y+1 << "\n";
        a[x] += a[y];
    }
    // cout << a << endl;
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
