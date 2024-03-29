
#include <bits/stdc++.h>
// #define SINGLE_INPUT
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

void sol() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i:a) cin >> i;
    int l = 0, r = n-1;
    while (l+1<n && a[l] >= a[l+1]) l++;
    while (r>=1 && a[r-1] <= a[r]) r--;
    // cout << l << " " << r << endl;
    if (l<r) {
        int ls = 0, rs = 0;
        for (int i=l+1; i<=r; i++) {
            if (a[i-1] > a[i]) ls += a[i-1]-a[i];
        }
        for (int i=r-1; i>=l; i--) {
            if (a[i] < a[i+1]) rs += a[i+1]-a[i];
        }
        if (a[l]>=ls && a[r]>=rs)
            cout << "YES\n";
        else 
            cout << "NO\n";
    } else {
        cout << "YES\n";
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
