#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
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
    string s;
    cin >> s;
    vector<int> c(256);
    string ans;
    int x = 0, y = 0;
    for (char i:s) {
        c[i]++;
        if (i == 'N' || i == 'S') {
            ans.push_back(c[i]%2?'R':'H');
        } else {
            ans.push_back(c[i]%2?'H':'R');
        }
        
    }
    // cout << ans << "\n";
    int x1=0, y1=0, x2=0, y2=0;
    for (int i=0; i<n; i++) {
        if (ans[i] == 'H') {
            if (s[i] == 'N') x1++;
            if (s[i] == 'S') x1--;
            if (s[i] == 'E') y1++;
            if (s[i] == 'W') y1--;
        } else {
            if (s[i] == 'N') x2++;
            if (s[i] == 'S') x2--;
            if (s[i] == 'E') y2++;
            if (s[i] == 'W') y2--;
        }
    }
    if (x1 != x2 || y1 != y2 || count(ans.begin(), ans.end(), 'H')%n == 0) {
        cout << "NO\n"; 
        return ;
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