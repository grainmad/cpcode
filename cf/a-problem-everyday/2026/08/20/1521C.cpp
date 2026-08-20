
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

int ask(int t, int i, int j, int x) {
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    int a;
    cin >> a;
    return a;
}

void sol() {
    int n;
    cin >> n;
    // min(max(a[i],1), max(a[j],2)) min(a[i], max(a[j], 2))
    // max(min(a[i],1), min(a[j],2)) max(1, min(a[j], 2)) = 1 if a[j] = 1
    // max(min(a[i],n-1), min(a[j],n)) = a[j] if a[i] = 1
    int idx1 = 0;
    for (int i=1; i<n; i+=2) {
        int x = ask(2, i, i+1, 1);
        cerr << x << endl;
        if (x == 1) {
            idx1 = i;
        } else if (x == 2) {
            if (ask(1, i, i+1, 1) == 1) idx1 = i+1;
        }

    }
    if (n%2) {
        int x = ask(2, n-1, n, 1);
        if (x == 1) {
            idx1 = n-1;
        } else if (x == 2) {
            if (ask(1, n-1, n, 1) == 1) idx1 = n;
        }
    }
    vector<int> a(n+1);
    a[idx1] = 1;
    for (int i=1; i<=n; i++) {
        if (i != idx1) {
            a[i] = ask(1, idx1, i, n-1);
        }
    }
    cout << "!";
    for (int i=1; i<=n; i++) {
        cout << " " << a[i];
    } 
    cout << endl;
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
