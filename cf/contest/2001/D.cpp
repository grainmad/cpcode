#include <bits/stdc++.h>
// #define SINGLE_INPUT
#define ull unsigned long long
#define ll long long
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
template<class t> ostream& operator<<(ostream& os,const multiset<t>& v) {
    os<<'['; int s = 1;
    for(auto e:v) { if (s) s = 0; else os << ", "; os << e; }
    return os<<']';
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
    for (int& i:a) cin >> i;
    multiset<int> st;
    vector<int> ans;
    vector<int> usd(n+1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (int i=n-1; i>=0; i--) {
        if (!st.count(a[i])) pq.emplace(i, a[i]), st.insert(a[i]);
    }
    int m = st.size();
    st.clear();
    int p = 0, pt = 0;
    for (int i=0; i<m; i++) {
        while (pq.size() && usd[pq.top().second]) pq.pop();
        while (pq.size() && pt<=pq.top().first) {
            if (!usd[a[pt]]) st.insert(a[pt]);
            pt++;
        }
        int mx = i%2 ? *st.begin() : *st.rbegin();
        ans.push_back(mx);
        usd[mx] = 1;
        while (st.find(a[p])==st.end() || *st.find(a[p]) != mx) {
            auto it = st.find(a[p]);
            if (it != st.end()) st.erase(it);
            p++;
        }
        st.erase(mx);
    }
    cout << m << "\n";
    for (int i:ans) {
        cout << i << " ";
    } cout << "\n";
    // cout << ans << endl;
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