
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
    for (auto& i:a) cin >> i;
    int p = -1;
    for (int i=1; i<2*n; i++) {
        if (a[i%n] == a[(i-1)%n]) {
            p = i%n;
            break;
        }
    }
    if (p == -1) {
        if (n%2) {
            cout << "3\n3";
            for (int i=1; i<n; i++) {
                cout << " " << (i%2+1);
            }
            cout << "\n";
        } else {
            cout << "2\n";
            for (int i=0; i<n; i++) {
                cout << (i%2+1) << " ";
            }
            cout << "\n";
        }
    } else {
        vector<int> ans(n);
        int c = 1;
        for (int i=0; i<n; i++) {
            if (a[(i+p-1+n)%n] != a[(i+p)%n]) {
                c = 3-c;
            }
            ans[(i+p)%n] = c;
        }
        cout << (count(ans.begin(), ans.end(), 1) == n ? 1 : 2) << "\n";
        for (int i:ans) {
            cout << i << " ";
        }
        cout << "\n";
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
