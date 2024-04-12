
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
    string s, t;
    cin >> s >> t;
    vector<int> cs(26), ct(26);
    for (char i:s) cs[i-'a']++;
    for (char i:t) ct[i-'a']++;
    if (cs != ct) {
        cout << "NO\n";
        return ;
    }
    if (count_if(cs.begin(), cs.end(), [](auto x)->bool {return x > 1;}) > 0) {
        cout << "YES\n";
        return ;
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        return tie(t[x], s[x]) < tie(t[y], s[y]);
    });
    string ss, st;
    for (int i:idx) {
        ss.push_back(s[i]);
        st.push_back(t[i]);
    }
    // cout << s << " " << t << endl;
    // cout << ss << " " << st << endl;
    vector<int> cnt(256);
    int rs = 0;
    for (char i:ss) {
        for (char j=i+1; j<='z'; j++) {
            rs += cnt[j];
        }
        cnt[i]++;
    }
    cout << (rs%2?"NO\n":"YES\n");
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
