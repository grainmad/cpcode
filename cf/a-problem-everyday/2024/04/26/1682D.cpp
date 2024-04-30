
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
    string s;
    cin >> s;
    int c1 = count(s.begin(), s.end(), '1');
    if (c1%2 || c1 == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int p = 0;
        for (int i=0; i<n; i++) {
            if (s[(i+n-1)%n] == '1' && s[i] == '0') p = i;
        }
        for (int i=0; i<n; i++) {
            int j = i;
            while (j<n && s[j] != '1') j++;
            if (p%n != i && s[(i+n-1)%n] == '1') {
                cout << p%n+1 << " " << i+1 << "\n";
            }
            for (int t=i; t<j; t++) {
                cout << t%n+1 << " " << (t+1)%n+1 << "\n";
            }
            i = j;
        }
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
