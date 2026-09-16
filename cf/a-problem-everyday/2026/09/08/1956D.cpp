
#include <bits/stdc++.h>
#define SINGLE_INPUT
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
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    int n;
    cin >> n;
    vector<int> a(n+2);
    for (int i=1; i<=n; i++) cin >> a[i];

    // debug start
    auto trans = [&](int l, int r) {
        cout << "from:" << a << endl;
        set<int> st;
        for (int i=l; i<=r; i++) {
            st.insert(a[i]);
        }
        int x = 0;
        while (st.count(x)) x++;
        for (int i=l; i<=r; i++) {
            a[i] = x;
        }
        cout << "to:" << a << endl;
    };
    // debug end
    vector<pair<int,int>> st;
    
    auto opt = [&](int l, int r) { // let [l .. r] r-l+1个r-l+1
        for (int i=l; i<=r; i++) {
            if (a[i]) st.emplace_back(i, i);
        }
        function<void(int)> g = [&](int x) {
            if (x == 0) return ;
            g(x-1);
            st.emplace_back(l, l+x);
            st.emplace_back(l, l+x-1);
            g(x-1);
        };
        g(r-l); // 0 .. r-l
        st.emplace_back(l, r);
    };

    vector<int> f(n+2), lk(n+2);
    for (int i=1; i<=n+1; i++) {
        for (int j=0; j<i; j++) {
            if (f[i] < f[j]+(i-j-1)*(i-j-1)+a[i]) {
                f[i] = f[j]+(i-j-1)*(i-j-1)+a[i];
                lk[i] = j;
            }
        }
    }
    int pt = n+1;
    while (pt) {
        // (lk[pt], pt) -> opt [lk[pt]+1, pt-1]
        if (lk[pt]+1 < pt) {
            opt(lk[pt]+1, pt-1);
        }
        pt = lk[pt];
    }
    cout << f[n+1] << " " << st.size() << "\n";
    for (auto& [x, y]:st) {
        cout << x << " " << y << "\n";
        // trans(x, y);
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