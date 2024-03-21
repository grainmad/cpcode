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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int l = 0;
    while (l<n) {
        int r = min(l+k, n);
        // cout << l << " " << r << endl;
        int m = r-l, c = (m+1)/2;
        for (int i=l; i<r; i++,c++) {
            a[i] = l+c%m;
        }
        l += k;
    }
    for (int i:a) {
        cout << i + 1 << " ";
    }
    cout << "\n";
    cout << (n+k-1)/k << "\n";
    for (int i=0; i<n; i++) {
        cout << i/k+1 << " ";
    }
    cout << "\n";
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