
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
    vector<int> cnt(n+1);
    for (int i=1; i<n; i++) {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y]++;
    }
    int ok = 1;
    if (cnt[n] != n-1) ok = 0;
    for (int i=1,s=0; i<n; i++) {
        s += cnt[i];
        if (s > i) ok = 0;
    }
    if (ok) {
        cout << "YES\n";
        vector<int> st;
        for (int i=1; i<n; i++) {
            if (cnt[i] == 0) st.push_back(i);
            else {
                int u = i;
                for (int j=1; j<cnt[i]; j++) {
                    cout << u << " " << st.back() << "\n";
                    u = st.back();
                    st.pop_back();
                }
                cout << u << " " << n << endl;
            }
        }
    } else {
        cout << "NO\n";
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
