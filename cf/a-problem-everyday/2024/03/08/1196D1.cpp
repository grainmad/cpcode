
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

const string C = "RGB";

auto check(auto& s, int l, int r) {
    int rt = r-l+1;
    for (int c=0; c<3; c++) {
        int cnt = 0;
        for (int i=l; i<=r; i++) {
            if (C[(c+i)%3] != s[i]) cnt++;
            // cout << s[i];
        }
        // cout << endl;
        rt = min(rt, cnt);
    }
    // cout << rt << "---\n";
    return rt;
}

void sol() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = n;
    for (int i=0; i<=n-k; i++) {
        ans = min(ans, check(s, i, i+k-1));
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
