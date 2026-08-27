
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
    for(auto [x,y]:mp) { if (s) s = 0; else os<<x<<": "<<y; }
    return os<<'}';
}

void sol() {
    int n, k;
    cin >> n >> k;
    k = n*(n-1)/2-k;
    int sz = n*(n-1)/2;
    int f[n+1][sz+1];
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<sz; j++) {
            for (int t=1; t+i<=n && j+t*(t-1)/2<=sz; t++) {
                f[i+t][j+t*(t-1)/2] |= f[i][j];
            }
        }
    }
    // for (int i=0; i<=n; i++) {
    //     for (int j=0; j<=sz; j++) {
    //         cout << i << "," << j << "=" << f[i][j] << endl;
    //     }
    // }
    if (f[n][k]) {
        vector<int> st;
        int u = n, v = k;
        while (u) {
            int i = 1;
            for (; !f[u-i][v-i*(i-1)/2]; i++);
            st.push_back(i);
            u -= i;
            v -= i*(i-1)/2;
        }
        // cout << st << endl;
        u = n;
        while (st.size()) {
            for (int i=u-st.back()+1; i<=u; i++) {
                cout << i << " ";
            }
            u -= st.back();
            st.pop_back();
        }
        cout << "\n";
    } else {
        cout << "0\n";
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
