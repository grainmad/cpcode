
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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    // auto check = [&]() {
    //     for (int i=1; i<n; i++) {
    //         if (a[i] < a[i-1]-1) {
    //             return false;
    //         }
    //     }
    //     return true;
    // };
    // int cnt = 0;
    // do {
    //     if (check()) {
    //         cout << a << " ";
    //         cout << (cnt++);
    //         cout << endl;
    //     }
    // }
    // while (next_permutation(a.begin(), a.end()));
    k--;
    int p = 60;
    while (k>0 && p != -1) {
        // cout << k << endl;
        while (p>0 && k<=(1LL<<p-1)-1) p--; // 最后一个大于等于k的位置
        ll s = (1LL<<p)-1;
        int l = n-1-p;
        if (l<0) break;
        while (p>0 && s-(1LL<<p-1)+1 <= k) p--; // 最后一个差值小于等于k的位置
        k -= s-(1LL<<p)+1;
        int r = n-p;
        // cout << l << " " << r << endl;
        reverse(a.begin()+l, a.begin()+r);
        p--;
    }
    if (k > 0) {
        cout << "-1\n";
    } else {
        // cout << a << "\n";
        for (int i:a) {
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
